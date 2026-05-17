#include <bits/stdc++.h>
using namespace std;

// void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&state){
//     //iterate troguht my parent and my children
//     set<int>s;
//     for(int i=0;i<=6;i++){
// 	s.insert(i);
//     }
//     for(auto u:adj[node]){
// 	if(u==-1)continue;
// 	s.erase(state[u]);
// 	for(auto v:adj[u]){
// 	    if(v==-1)continue;
// 	    s.erase(state[v]);
// 	}
//     }
//     state[node]=*s.begin();
//     //find the smallest number not found it 
//     for(auto u:adj[node]){
// 	if(u==parent) continue;
// 	dfs(u,node,adj,state);
//     }
// }

int main() {
    ifstream in("planting.in");
    int n;
    in>>n;
    vector<int>adj(n);
    for(int i=0;i<n-1;i++){
	int a,b;
	in>>a>>b;
	adj[--a]++;
	adj[--b]++;
    }
    ofstream out("planting.out");
    out<<1+*max_element(adj.begin(),adj.end());

    return 0;
}
// 4 1 2 4 3 2 3
