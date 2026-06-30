#include <bits/stdc++.h>
using namespace std;

//each graph has a winning player
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>v(n);
	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    v[--a].push_back(--b);
	    v[b].push_back(a);
	}
    }
    return 0;
}
