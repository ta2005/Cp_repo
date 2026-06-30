import json
import urllib.request
import os
import re
from difflib import SequenceMatcher

# 1. Fetch Codeforces problems
url = "https://codeforces.com/api/problemset.problems"
print("Fetching Codeforces problems...")
req = urllib.request.Request(url)
with urllib.request.urlopen(req) as response:
    data = json.loads(response.read().decode())

problems = data['result']['problems']
print(f"Loaded {len(problems)} problems.")

# Build a simpler list: [{"name": "A and B", "tags": ["math", "dp", ...]}, ...]
# Also normalize the name to lower alphanumeric for easier matching
def normalize(s):
    return re.sub(r'[^a-z0-9]', '', s.lower())

cf_problems = []
for p in problems:
    if 'name' in p and 'tags' in p:
        cf_problems.append({
            'name': p['name'],
            'norm': normalize(p['name']),
            'tags': p['tags']
        })

# 2. Get local files
unsorted_dir = os.path.expanduser("~/Training/Unsorted")
files = [f for f in os.listdir(unsorted_dir) if f.endswith(".cpp")]

print(f"Found {len(files)} files in Unsorted.")

def similarity(a, b):
    return SequenceMatcher(None, a, b).ratio()

# 3. Match and categorize
categories = {}
unmatched = []

for file in files:
    base = file[:-4] # remove .cpp
    norm_base = normalize(base)
    
    # Try exact normalized match first
    best_match = None
    for p in cf_problems:
        if norm_base == p['norm']:
            best_match = p
            break
            
    # If not exact, maybe fuzzy or substring?
    if not best_match:
        best_score = 0
        for p in cf_problems:
            if len(norm_base) > 3 and (norm_base in p['norm'] or p['norm'] in norm_base):
                # Basic substring
                score = min(len(norm_base), len(p['norm'])) / max(len(norm_base), len(p['norm']))
                if score > best_score:
                    best_score = score
                    best_match = p
            else:
                score = similarity(norm_base, p['norm'])
                if score > 0.90 and score > best_score:
                    best_score = score
                    best_match = p
                    
    if best_match:
        tags = best_match['tags']
        if not tags:
            tag = "misc"
        else:
            # Codeforces tags often include things like 'greedy', 'math', 'dp', 'implementation'
            # Let's filter out 'implementation' if there are other tags, as it's too generic
            tag = tags[0]
            if tag == 'implementation' and len(tags) > 1:
                tag = tags[1]
        
        if tag not in categories:
            categories[tag] = []
        categories[tag].append((file, best_match['name']))
    else:
        unmatched.append(file)

print("\n--- Match Results ---")
for tag, matched_files in categories.items():
    print(f"\n[{tag.upper()}] ({len(matched_files)} files):")
    for f, p_name in matched_files:
        print(f"  {f} -> {p_name}")

print(f"\n[UNMATCHED] ({len(unmatched)} files):")
print(", ".join(unmatched))
