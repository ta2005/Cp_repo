#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>pos;
pair<int,int>x;
pair<int,int>y;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node]=true;
    for(auto u:adj[node]){
	if(visited[u])continue;
	x.first=max(x.first,pos[u].first);
	x.second=min(x.second,pos[u].first);
	y.first=max(y.first,pos[u].second);
	y.second=min(y.second,pos[u].second);
	dfs(u,adj,visited);
    }
}

int main() {
    ifstream in("fenceplan.in");
    int n,m;
    in>>n>>m;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
	in>>v[i].first>>v[i].second;
    }
    pos=v;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
	int a,b;
	in>>a>>b;
	--a;--b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    vector<bool>visited(n,false);
    long long res{LONG_LONG_MAX};
    for(int i=0;i<n;i++){
	if(!visited[i]){
	    x={pos[i].first,pos[i].first};
	    y={pos[i].second,pos[i].second};
	    dfs(i,adj,visited);
	    long long perim = 2LL*(x.first-x.second + y.first-y.second);
	    res=min(res,perim);
	}
    }
    ofstream out("fenceplan.out");
    out<<res;

    return 0;
}
