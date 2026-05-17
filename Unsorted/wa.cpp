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
	vector<int>v(n+1);
	for(int i=1;i<=n;i++){
	    cin>>v[i];
	}
	int res{};
	vector<bool> m(n);
	for(int i=1;i<=n;i++){
	    // if(m[i]==true) break;
	    // res++;
	    if(v[i]<=i) m[v[i]-1]=true;
	}
	cout<<res<<'\n';
    }
    return 0;
}
// 4 3 3 2 1 5 4 3 2 5 1 4 4 2 1 3 4 2 3 4 1
