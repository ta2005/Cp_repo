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
	vector<long long>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	long long res{};
	int l=0;
	int r=1;
	while(r<n){
	    while(r<n && 2*v[r]>v[r-1]){
		r++;
	    }
	    res+=max((r-l)-k,0);
	    l=r;
	    r++;
	}
	cout<<res<<'\n';
    }

    return 0;
}

// 6 4 2 20 22 19 84 5 1 9 5 3 2 1 5 2 9 5 3 2 1 7 2 22 12 16 4 3 22 12 7 3 22 12 16 4 3 22 12 9 3 3 9 12 3 9 12 3 9 12
