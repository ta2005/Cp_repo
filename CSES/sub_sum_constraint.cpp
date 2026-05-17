#include <bits/stdc++.h>
#include <vector>
using namespace std;
//this is graph problem(the graph is supoer cool) where each node is an index in array
//and the the weight of the edge is the sum aske for 
//for the arrray to be constrocable it is required 
//that going from the the same sum
//the construction of the array :
//i can subdivsie the array to the smallest possible values
//and then construct the array by subdivisions
//or using dfs this is what i want ot know 
//ohhhhhhhhhhhhhh i will use diajkstra from the first non empty node to the end of the other node
//and then i will be able to know th intermediate value
//and construct my array

void dfs(int node,vector<vector<pair<int,int>>>&v,vector<bool>&visited,vector<int>&pref){
    for (auto i:v[node]){
	if (visited[i.first]){
	    if(pref[i.first]!=(pref[node]+i.second)){
		std::cout<<"NO";
		std::exit(0);
	    } else{
		continue;
	    }
	}
	visited[i.first]=true;
	pref[i.first]=pref[node]+i.second;
	dfs(i.first,v,visited,pref);
    }
}

//in cp terms what does i mean for the sum from l(1-indexed) to r to be eq to s 
//let p be the prefix sum of the resulting arrray
//and p[r]-[l-1]=s;
//and my result will be the difference between these p[i+1]-p[i]
//and the graph is the nodes of the prefix array
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> v(n+1);
    vector<int> pref(n+1);
    vector<bool>visited(n+1);
    for (int i=0;i<m;i++){
	int l,r,s;
	cin>>l>>r>>s;
	v[--l].push_back({r,s});
	v[r].push_back({l,-s});
    }
    dfs(0,v,visited,pref);
    for (int i=0;i<n;i++) {
	cout<<pref[i+1]-pref[i];
    }
    	
    return 0;
}
// 5 3 1 3 3 3 5 3 4 4 -1
