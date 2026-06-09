#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node]=true;    
    for(auto u:adj[node]){
	if(visited[u])continue;
	dfs(u,adj,visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>lang(m);
    //so here is a shower realization 
    //the poeple themselves don't matter
    int illeterate{};
    for(int i=0;i<n;i++){
	int nbr;cin>>nbr;
	illeterate+=nbr==0;
	if(nbr==0) continue;
	int first;cin>>first;
	--first;
	lang[first].push_back(first);
	//i don't need to link all of the nodes 
	//i can have the first be like a hub to jumb between them
	for(int j=1;j<nbr;j++){
	    int u;cin>>u; 
	    lang[first].push_back(--u);
	    lang[u].push_back(first);
	}
    }
    vector<bool>visited(m);
    int nbr_comp{};
    for(int i=0;i<m;i++){
	if(lang[i].size()==0)continue;
	if(!visited[i]){
	    nbr_comp++;
	    dfs(i,lang,visited);
	}
    }
    cout<<max(nbr_comp-1,0)+illeterate;

    return 0;
}

// 5 5 1 2 2 2 3 2 3 4 2 4 5 1 5
