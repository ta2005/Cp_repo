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
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];	    
	}
	vector<long long >pref(n+1);
	for(int i=1;i<=n;i++){
	    pref[i]=pref[i-1]+v[i-1];
	}
	long long int res{};
	for(int k=1;k<=(n/2);k++){
	    if (n%k!=0) continue;
	    long long mx{0};
	    long long mn{LONG_LONG_MAX};
	    for(int j=k;j<=n;j+=k){
		mx=max(mx,pref[j]-pref[j-k]);
		mn=min(mn,pref[j]-pref[j-k]);
	    }
	    res=max(res,mx-mn);
	}	
	cout<<res<<'\n';
    }
}

// 5 2 1 2 6 10 2 3 6 1 3 4 1000000000 1000000000 1000000000 1000000000 15 60978 82265 78961 56708 39846 31071 4913 4769 29092 91348 64119 72421 98405 222 14294 8 19957 69913 37531 96991 57838 21008 14207 19198
