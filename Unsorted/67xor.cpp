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
	vector<int> v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}	
	sort(v.begin(),v.end());
	int acc{};
	for(int i=0;i<n-1;i++){
	    acc^=v[i];
	}	
	cout<<(v[n-1]^acc)<<'\n';
    }

    return 0;
}

// 3 2 67 67 3 1 2 3 10 67 667 167 867 267 467 367 567 767 967
