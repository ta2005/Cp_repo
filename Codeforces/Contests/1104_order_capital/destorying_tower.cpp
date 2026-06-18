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
	for(int i=0;i<n ;i++){
	    for(int j=i+1;j<n ;j++){
		if(v[j]>v[i]){
		    v[j]=v[i];
		    break;
		}
	    }
	}
	long long res{};
	for(int i=0;i<n;i++){
	    res+=v[i];
	}
	cout<<res<<'\n';
    }

    return 0;
}
// 10 3 1 3 5 3 5 4 3 4 3 2 5 1 4 2 1 4 3 5 4 1 3 5 2 5 2 2 3 1 4 1 7 6 6 1 5 2 4 3 4 1 1 1 1 5 10 3 8 6 9
