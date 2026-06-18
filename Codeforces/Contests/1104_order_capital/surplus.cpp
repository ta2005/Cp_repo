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
	vector<long long>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	for(int i=0;i<(n-1);i++){
	    if(v[i+1]<v[i]){
		v[i+1]+=v[i];
	    }
	}
	cout<<v[n-1]<<'\n';
    }
    return 0;
}

// 10 4 1 2 2 5 2 7 3 3 3 2 1 5 2 2 1 3 3 4 3 1 4 2 5 1 4 3 2 5 6 6 2 5 1 4 3 7 2 7 1 6 3 5 4 8 8 1 7 2 6 3 5 4 5 1000000000 999999999 999999998 999999997 999999996
