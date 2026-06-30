#include <bits/stdc++.h>
using namespace std;

struct cow{
    int x,y,p;
};

long long distance(cow a,cow b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node]=true;
    for(auto u:adj[node]){
	if(visited[u])continue;
	dfs(u,adj,visited);
    }
}

int main() {
    ifstream in("moocast.in");
    int n;in>>n;
    vector<cow>v(n);
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
	in>>v[i].x>>v[i].y>>v[i].p;
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    if(i==j)continue;
	    if(distance(v[i],v[j])<v[i].p*v[i].p){
		adj[i].push_back(j);
	    }
	}
    }
    int res=0;
    for(int i=0;i<n;i++){
	vector<bool>visited(n);
	dfs(i,adj,visited);
	int count{};
	for(auto c:visited){
	    count+=c;
	}
	res=max(res,count);
    }
    ofstream out("moocast.out");
    out<<res;
    return 0;
}
