#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int t;
    cin>>t;
    while (t--){
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for (int i=0;i<n;i++){
	    cin>>v[i];
	    v[i]%=m;
	}
    }
}

// 1<x<m it must minimize it fo all intergers
// farmer jon will then need to add the min(ai%m,m-ai%m)
// 2 5 9 15 12 18 3 8 3 69 1 988244353 998244853
