#include <bits/stdc++.h>
using namespace std;

int dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
    int acc{1};
    visited[node]=true;
    for(auto u:adj[node]){
	if(visited[u])continue;
	acc+=dfs(u,adj,visited);
    }
    return acc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
	int a,b;
	cin>>a>>b;
	--a;--b;
	adj[a].push_back(b);
    }
    long long res{};
    for(int i=0;i<n;i++){
	vector<bool>visited(n,false);
	res+=dfs(i,adj,visited);
    }
    cout<<res;
    return 0;
}
