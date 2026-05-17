#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,int x,int id){
    vis[node]=id;
    for(auto u:adj[node]){
	if(u.second<x) continue;
	if(vis[u.first]!=-1)continue;
	vis[u.first]=id;
	dfs(u.first,adj,vis,x,id);
    }
}

bool check(int x,vector<int>&v,vector<vector<pair<int,int>>>&adj){
    //i will simply discard any portal with width less then x
    //let us say i am at node i and i!=v[i] I need to got to v[i]
    //then i will do a dfs from that v[i]
    //to reach the node i want to reach
    //i return no well try to find connected components
    //but how do i make sure i don't fuck up the other nodes..
    //when i do swaps
    vector<int>cmp(v.size(),-1);
    int id=0;
    for(int i=0;i<(int)v.size();i++){
	if(cmp[i]==-1){
	    dfs(i,adj,cmp,x,id++);
	}
    }
    for(int i = 0; i < (int)v.size(); i++){
	if(cmp[i] != cmp[v[i]]){
	    return false;
	}
    }
    return true;
}

int main() {
    ofstream out("wormsort.out");
    ifstream in("wormsort.in");
    int n,m;
    in>>n>>m;
    vector<int>v(n);
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<n;i++){
	in>>v[i];
	v[i]--;
    }
    int max_width{};
    for(int i=0;i<m;i++){
	int a,b,w;
	in>>a>>b>>w;
	adj[--a].push_back({--b,w});
	adj[b].push_back({a,w});
	max_width=max(w,max_width);
    }
    if(std::is_sorted(v.begin(),v.end())){
	out<<-1;
	return 0;
    }
    long long int l=1;
    long long int r=max_width;
    while(l<r){
	long long mid=(l+r+1)/2;//i don't have to worry about overflow
	if(check(mid,v,adj)){
	    l=mid;
	}else{
	    r=mid-1;
	}
    }
    out<<l;
    return 0;
}
