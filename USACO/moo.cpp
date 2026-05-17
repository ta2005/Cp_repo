#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    string s;
    cin >> s;
    map<string, int> v;
    for (int i = 0; i < n-2; i++) {
	if (s[i + 1] == s[i + 2] && s[i] != s[i + 1]) {
	    v[s.substr(i, 3)]++;
	}
    }
    map<string, int> add;
    for (int i = 0; i < n-2; i++) {
	if (s[i + 1] != s[i + 2]) {
	    if(s[i]!=s[i+1]){
		string a = s.substr(i, 3);
		a[1] = a[2];
		add[a]=1;
	    }
	    if (s[i]!=s[i+2]){
		string b = s.substr(i, 3);
		b[2] = b[1];
		add[b]=1;
	    }
	} else if (s[i + 1] == s[i + 2] && s[i] == s[i + 1]) {
	    string a = s.substr(i, 3);
	    for (char c = 'a'; c <= 'z'; c++) {
		if (c == s[i]) {
		    continue;
		}
		a[0] = c;
		add[a]=1;
	    }
	}
    }
    for (const auto&i : add){
	v[i.first]++;
    }
    set<string> res;
    
    for (const auto&i : v){
	if (i.second>=f)
	    res.insert(i.first);
    }
    cout<<res.size()<<'\n';
    for(auto i:res){
	cout<<i<<'\n';
    }
}
// 17 2 momoobaaaaaqqqcqq
