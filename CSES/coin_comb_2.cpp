#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    constexpr int mod = 1e9 +7;
    vector<int>v(n); 
    vector<int>res(1e6+5);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    res[0]=1;
    for(int j=0;j<n;j++){
	for(int i=0;i<=x;i++){
	    if(i+v[j]<=x){
		res[i+v[j]]+=res[i];
		res[i+v[j]]%=mod;
	    }
	}
    }
    cout<<res[x];
    return 0;
}

// 3 9 2 3 5
