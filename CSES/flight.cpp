#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<bool>& visited,vector<vector<int>>&v){
    for (int i:v[node]){
	if (visited[i]) continue;
	visited[i]=true;
	dfs(i,visited,v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n);
    vector<vector<int>> w(n);
    for (int i=0;i<m;i++){
	int a;
	int b;
	cin>>a>>b;
	v[--a].push_back(--b);
	//this is to check if every one can reach the same node
	w[b].push_back(a);
    }
    vector<bool>visited(n);
    vector<bool>visited1(n);
    visited[0]=true;
    visited1[0]=true;
    dfs(0,visited,v);
    dfs(0,visited1,w);
    bool poss = true;
    pair<int,int> wa;
    for (int i=0;i<n && poss;i++){
	if  (!visited[i]){
	    poss=false;
	    wa.first=1;
	    wa.second=i+1;
	}
	if  (!visited1[i]){
	    poss=false;
	    wa.second=1;
	    wa.first=i+1;
	}
    }
    if (poss){
	cout<<"YES";
    }else{
	cout<<"NO\n";
	cout<<wa.first<<' '<<wa.second;
    }
    return 0;
}
// 4 5 1 2 2 3 3 1 1 4 3 4
