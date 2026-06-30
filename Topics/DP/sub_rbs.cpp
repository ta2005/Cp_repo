#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<long long>pref(n+1);
	//to algo will run one to find all 
	for(int i=0;i<n;i++){
	    pref[i+1]=pref[i]+(s[i]=='('?1:-1);
	}
	int m = *max_element(pref.begin(),pref.end());
	for(int i=0;i<n;i++){
	}
    }

    return 0;
}
