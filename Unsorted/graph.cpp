#include <bits/stdc++.h>
using namespace std;


void dfs(int i,vector<bool>&visited,vector<vector<int>>&v){
    if (visited[i]) return;
    visited[i]=true;
    cout<<i<<'\n';
    for (auto j:v[i]){
	dfs(j,visited,v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> v(n+1);
    for (int i=0;i<q;i++){
	int a,b;
	cin>>a>>b;
	v[a].push_back(b);
	v[b].push_back(a);
    }
    vector<bool> visited(n+1);
    dfs(1,visited,v);

    return 0;
}
// 9 9 1 2 1 3 1 4 2 5 2 6 3 7 4 8 6 9 7 9
