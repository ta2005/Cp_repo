#include <bits/stdc++.h>
using namespace std;


using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;

void dfs(int node,vvi v,vvb touched,vvi visited_state){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vvi v(n,vector<int>(m));
    vvb tounched(n,vector<bool>(m));
    vvi visited_state(n,vector<int>(m));
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    cin>>v[i][j];
	}
    }
    
    return 0;
}
