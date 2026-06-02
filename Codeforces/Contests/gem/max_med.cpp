#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n,k;
    cin>>n>>k;
    vector<long long int>v(n);
    vector<long long int>pref(n+1);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
	pref[i+1]=pref[i]+v[i];
    }
    int index{};
    for(long long int i=(n/2);i<n;i++){
	long long cost=(long long)(v[i]*(i-n/2))-(pref[i]-pref[n/2]);
	// cout<<cost<<'\n';
	if(cost<=k){
	    index=i;
	}
    }
    long long cost=(long long)(v[index]*(index-n/2))-(pref[index]-pref[n/2]);
    long long res=v[index];
    res+=(k-cost)/(n/2+1);
    cout<<res;
    return 0;
}

// 5 5 1 2 1 1 1
