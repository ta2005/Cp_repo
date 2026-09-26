#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    constexpr int mod = 1e9+7;
    vector<int>v(n);
    vector<int>res(1e6+5);
    for(int i=0;i<n;i++){
	cin>>v[i];
	res[v[i]]=1;
    }
    // the nbr of way to make x is
    // nbr of ways to make x-c for all c
    for(int i=0;i<=x;i++){
	for(int j=0;j<n;j++){
	    if(i+v[j]<=x){
		res[i+v[j]]+=res[i];
		res[i+v[j]]%=mod;
	    }
	}
    }
    cout<<res[x];
    return 0;
}
