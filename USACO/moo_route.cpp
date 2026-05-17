#include <bits/stdc++.h>

using namespace std;

struct e{
    int dest,dep,arr;
    bool operator < (const e&other){
	return this->dep<other.dep;
    }
};

void dfs(int node,vector<vector<e>>&v,int n,vector<int>&visited,int time,vector<int>&cust){
    for (auto i:v[node]){
	//now i need to determie the time of going out
	if (node!=0 && (i.dep)<(time+cust[node]))continue;
	if(visited[i.dest]!=-1 && visited[i.dest]<=i.arr) continue;
	visited[i.dest]=i.arr;
	dfs(i.dest,v,n,visited,i.arr,cust);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<e>> v(n);
    vector<int> d(n);
    //this is a directed 
    for (int i=0;i<m;i++){
	int c,r,d,s;
	cin>>c>>r>>d>>s;
	v[--c].push_back({--d,r,s});
    }
    for (int i=0;i<n;i++){
	cin>>d[i];
    }
    for (auto i:v){
	sort(i.begin(),i.end());
    }
    vector<int>visited(n,-1);
    vector<int>last(n,-1);
    visited[0]=0;
    dfs(0,v,n,visited,0,d);
    //i will need to travese the graph 
    for (auto i:visited){
	cout<<i<<'\n';
    }
    return 0;
}

// 3 3 1 0 2 10 2 11 2 0 2 1 3 20 10 1 10
