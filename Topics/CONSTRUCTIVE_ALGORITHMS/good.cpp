#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	vector<long long >pref(n+2);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    pref[i+1]=pref[i]+v[i];
	}
	pref[n+1]=pref[n];
	//first opservation to halve later is better than two half now
	long long res=LONG_LONG_MIN;
	//good good ....bad bad bad 
	for(int i=0;i<=n;i++){
	    long long count=pref[i] -(1LL*k*(i));
	    long long acc{};
	    for(int j=i;j<min(30+i,n);j++){
		acc+=v[j]/(1<<(j-i+1));
	    }
	    res=max(res,count+acc);
	}
	cout<<res<<'\n';
    }
    return 0;
}

// 5 4 5 10 10 3 1 1 2 1 3 12 10 10 29 12 51 5 74 89 45 18 69 67 67 11 96 23 59 2 57 85 60
