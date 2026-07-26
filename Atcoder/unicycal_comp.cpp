#include <bits/stdc++.h>
using namespace std;

long long  vertices;
long long  edges;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node]=true;
    vertices++;
    edges+=adj[node].size();
    for(auto u:adj[node]){
	if(visited[u])continue;
	dfs(u,adj,visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // this could be dsu but dfs is easier 
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
	int a,b;
	cin>>a>>b;
	--a;--b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    bool test=true;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
	if(visited[i])continue;
	vertices=0;
	edges=0;
	dfs(i,adj,visited);
	if(vertices!=edges/2){
	    test=false;
	    break;
	}
    }
    cout<<(test?"Yes\n":"No\n");

    return 0;
}
// 3 3 2 3 1 1 2 3
