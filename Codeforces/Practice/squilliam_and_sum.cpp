#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //this is a sparse table 
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    long long res{};
    vector<vector<int>>st(20,vector<int>(n));
    for(int i=0;i<n;i++){
	st[0][i]=v[i];
    }
    for(int i=1;i<=20;i++){
	for(int j=0;(j+(1<<i))<=n;j++){
	    st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	    res+=st[i][j];
	}
    }
    cout<<res;
    return 0;
}

// 3 4 12 21
