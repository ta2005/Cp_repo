#include <bits/stdc++.h>
using namespace std;

void color_graph(int node,vector<vector<int>>&adj,vector<bool>visited,vector<int>color,int c){
    visited[node]=true;
    color[node]=c;
    for(auto u:adj[node]){
	if(visited[u])continue;
	color_graph(u,adj,visited,color,1-c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>m;
    // for(;;m--){
	int n,k;
	cin>>n>>k;
	vector<vector<int>>adj(n);
	for(int i=0;i<k;i++){
	    int u,v;
	    cin>>u>>v;
	    --u;--v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	int mx=0;
	for(int i=0;i<n;i++){
	    vector<int>color(n);
	    vector<bool>visited(n);
	    color_graph(i,adj,visited,color,0);
	    int count{};
	    for(auto c:color){
		count+=(c==0);
	    }
	    mx=max(mx,count);
	}
	cout<<mx;
    // }
    return 0;
}
// 1 6 8 1 2 1 3 2 4 2 5 3 4 3 6 4 6 5 6
