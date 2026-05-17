#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,s;
	cin>>n>>s;
	vector<int>v(n);
	vector<int>pref(n+1);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    pref[i+1]=pref[i]+v[i];
	}
	int res{-1};
	for(int i=0;i<=n;i++){
	    auto it=upper_bound(pref.begin(),pref.end(),s+pref[i]);
	    it--;
	    if(*it-pref[i]==s){
		//to search for the last ele
		// int dis=(int)(it-pref.begin())-i+1;
		res=max(res,(int)(it-pref.begin())-i);
	    }
	}
	if(res!=-1){
	    cout<<n-res<<'\n';
	}else{
	    cout<<-1<<'\n';
	}
    }
    return 0;
}

// 7 3 1 1 0 0 3 1 1 1 0 9 3 0 1 0 1 1 1 0 0 1 6 4 1 1 1 1 1 1 5 1 0 0 1 1 0 16 2 1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1 6 3 1 0 1 0 0 0
