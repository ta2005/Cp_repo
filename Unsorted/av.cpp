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
	sort(v.begin(),v.end());
	cout<<v.back()<<'\n';
    }

    return 0;
}

// 3 4 3 3 3 3 5 7 1 6 9 9 5 3 4 4 4 3
