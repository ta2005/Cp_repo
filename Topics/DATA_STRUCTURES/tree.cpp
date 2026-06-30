#include <bits/stdc++.h>
using namespace std;


void dfs(int node,int parent,vector<vector<int>>&adj,vector<long long>&leaf){
    if(adj[node].size()==1){
	leaf[node]=1;
    }
    for(auto u:adj[node]){
	if(u==parent) continue;
	dfs(u,node,adj,leaf);
	leaf[node]+=leaf[u];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<vector<int>>v(n);
	v[0].push_back(-1);
	for(int i=0;i<n-1;i++){
	    int a,b;
	    cin>>a>>b;
	    v[--a].push_back(--b);
	    v[b].push_back(a);
	}
	vector<long long>leaf(n);
	dfs(0,-1,v,leaf);

	int q;cin>>q;
	for(int i=0;i<q;i++){
	    int a,b;
	    cin>>a>>b;
	    --a;
	    --b;
	    cout<<leaf[a]*leaf[b]<<'\n';
	}
    }

    return 0;
}

// 2 5 1 2 3 4 5 3 3 2 4 3 4 5 1 4 4 1 3 3 1 2 1 3 3 1 1 2 3 3 1
