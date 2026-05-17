#include <bits/stdc++.h>
using namespace std;
//i will have a vector
//with each cows move preferred gifts 
//and i need to find a path between them
//the cows are exchaging gifts
//i need to exchange gift 
// a-b
// b-c
// c-a
// this is a valid path 
// so i need to find a route from node 0 to node 0

int status=false;

void dfs(int node,vector<vector<int>>&v,vector<bool>&visited,int dest){
    //the fist time the dest is visited exit the fun
    status=visited[dest];
    if (visited[node]) return;
    visited[node]=true;
    for (int i:v[node]){
	dfs(i,v,visited,dest);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> cows(n);
    for (int i=0;i<n;i++){
	int j=0;
	for (j=0;j<n;j++){
	    int g;
	    cin>>g;
	    cows[i].push_back(--g);
	    if (g==i){
		break;
	    }
	}
	for (++j;j<n;j++){
	    int a;
	    cin>>a;
	}
    }
    for (auto i:cows){
	for(auto j:i){
	    cout<<j<<' ';
	}
	cout<<endl;
    }
    vector<int> res(n);
    vector<bool> skip(n);
    for (int i=0;i<n;i++){
	if (skip[i])continue;
	for(int j=0;j<cows[i].size();j++){
	    vector<bool> visited(n);
	    //cow i can exchange its gift with cows j only and only 
	    //if there exsits a route from i to j
	    //and it will finalyy reach its end because cows i 
	    //can always exchange whith cows i
	    dfs(i,cows,visited,j);
	}
    }
    for (auto i:res){
	cout<<i+1<<'\n';
    }

    return 0;
}
// 4 1 2 3 4 1 3 2 4 1 2 3 4 1 2 3 4
