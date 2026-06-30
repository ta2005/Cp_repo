import json
import urllib.request
import os
import re
import shutil
from difflib import SequenceMatcher

# 1. Fetch Codeforces problems
print("Loading Codeforces problems...")
with open(os.path.expanduser("~/Training/scripts/problems.json"), "r") as f:
    data = json.load(f)

problems = data['result']['problems']
print(f"Loaded {len(problems)} problems.")

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
base_dir = os.path.expanduser("~/Training")
unsorted_dir = os.path.join(base_dir, "Unsorted")
topics_dir = os.path.join(base_dir, "Topics")

if not os.path.exists(topics_dir):
    os.makedirs(topics_dir)

files = [f for f in os.listdir(unsorted_dir) if f.endswith(".cpp")]

def similarity(a, b):
    return SequenceMatcher(None, a, b).ratio()

# 3. Match and move
moved_count = 0

for file in files:
    base = file[:-4]
    norm_base = normalize(base)
    
    if len(norm_base) < 3:
        continue # Skip very short names, likely to false match

    best_match = None
    for p in cf_problems:
        if norm_base == p['norm']:
            best_match = p
            break
            
    if not best_match:
        best_score = 0
        for p in cf_problems:
            if len(p['norm']) > 3 and (norm_base in p['norm'] or p['norm'] in norm_base):
                score = min(len(norm_base), len(p['norm'])) / max(len(norm_base), len(p['norm']))
                if score > best_score:
                    best_score = score
                    best_match = p
            else:
                score = similarity(norm_base, p['norm'])
                if score > 0.90 and score > best_score:
                    best_score = score
                    best_match = p
                    
    if best_match and best_match['tags']:
        tag = best_match['tags'][0]
        if tag == 'implementation' and len(best_match['tags']) > 1:
            tag = best_match['tags'][1]
            
        # Clean up tag name for directory
        tag_dir_name = tag.replace(" ", "_").replace("*", "").upper()
        target_dir = os.path.join(topics_dir, tag_dir_name)
        
        if not os.path.exists(target_dir):
            os.makedirs(target_dir)
            
        src = os.path.join(unsorted_dir, file)
        dst = os.path.join(target_dir, file)
        shutil.move(src, dst)
        moved_count += 1
        print(f"Moved {file} -> {tag_dir_name}/ ({best_match['name']})")

print(f"\nSuccessfully categorized and moved {moved_count} files into ~/Training/Topics/")
print(f"Remaining unmatched files are still in ~/Training/Unsorted/")
