#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    vector<int>need(256);
    vector<int>have(256);
    for(int i=0;i<(int)(s.size());i++){
	need[s[i]]++;
    }
    for(int i=0;i<(int)(t.size());i++){
	have[t[i]]++;
    }
    int y{};
    int w{};
    for(int i=0;i<256;i++){
	if(need[i]==0) continue;
	int res=min(need[i],have[i]);
	y+=res;
	have[i]-=res;
	need[i]-=res;
    }
    for(int i=0;i<256;i++){
	w+=min(need[i],have[i^32]);
    }
    cout<<y<<' '<<w;

    return 0;
}
