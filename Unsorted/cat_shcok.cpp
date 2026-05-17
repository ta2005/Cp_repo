#include <bits/stdc++.h>
using namespace std;


set<int>path;
//connected cycles n n-1

bool find(int node,int parent,vector<vector<int>>&adj){
    path.insert(node);
    if((node+1)==(int)adj.size()){
	return true;
    }
    for(auto u:adj[node]){
	if(u==parent) continue;
	if(find(u,node,adj)){
	    return true;
	}
    }
    path.erase(node);
    return false;
}

bool dfs(int node,int parent,vector<vector<int>>&adj){
    if(parent!=-1){
	cout<<2<<' ';
    }
    int dest{-1};
    for(auto u:adj[node]){
	if(u==parent) continue;
	if(path.count(u)!=0){
	    dest=u;
	}else{
	    cout<<"1\n1\n";
	    cout<<2<<' '<<u<<'\n';
	}
    }
    dfs(dest,node,adj);
    return false;
}

//todo output the numebr of op to do
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<vector<int>>adj(n);
	adj[0].push_back(-1);
	for(int i=0;i<(n-1);i++){
	    int a,b;
	    cin>>a>>b;
	    adj[--a].push_back(--b);
	    adj[b].push_back(a);
	}
	//i will need to fint the route from node 1 to node n
	//we have two types of nodes nodes that are within the route and ones
	//that are not
	//for each node i 
	//i will delete all nodes that are not part of the route
	find(0,-1,adj);
	dfs(0,-1,adj);
	path.clear();
    }

    return 0;
}

// 4 5 1 2 2 3 1 5 5 4 2 1 2 4 1 2 1 3 1 4 6 1 2 1 3 3 4 4 5 4 6
