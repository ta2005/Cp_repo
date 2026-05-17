#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&v,vector<bool>&visited){
    if(visited[node]) return;
    visited[node]=true;
    if(node==(int)(v.size()-1)){
	dfs(node-1,v,visited);
	return;
    }
    int a = v[node+1]-v[node];
    int b= v[node]-v[node-1];
    if(a<b){
	dfs(node+1,v,visited);
    }else{
	dfs(node-1,v,visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream in("hoofball.in");
    int n;
    in>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	in>>v[i];
    }
    vector<bool>visited(n);
    sort(v.begin(),v.end());
    visited[0]=true;
    int count=1;
    dfs(1,v,visited);
    if(!visited[n-1]){
	count++;
    }
    dfs(n-1,v,visited);
    for(int i=1;i<n;i++){
	if(!visited[i]){
	    dfs(i,v,visited);
	    count++;
	}
    }
    ofstream out("hoofball.out");
    out<<count;
    return 0;
}
