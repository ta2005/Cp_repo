#include <bits/stdc++.h>
using namespace std;

//yeah global var are bad but it is what it is
int mn=INT_MAX;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&price){
    visited[node]=true;
    mn=min(mn,price[node]);
    for(auto i:adj[node]){
	if(visited[i]) continue;
	dfs(i,adj,visited,price);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    vector<vector<int>>friends(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    for(int i=0;i<m;i++){
	int u,v;
	cin>>u>>v;
	friends[--u].push_back(--v);
	friends[v].push_back(u);
    }
    long long int res{};
    vector<bool>visited(n);
    for(int i=0;i<n;i++){
	if(!visited[i]){
	    dfs(i,friends,visited,v);
	    res+=mn;
	    mn=INT_MAX;
	}
    }
    cout<<res;
    return 0;
}

// 5 2 2 5 3 4 8 1 4 4 5
