#include <bits/stdc++.h>
using namespace std;

int dfs(int node,vector<vector<int>>&adj,vector<int>&visited,int id){
    visited[node]=id;
    long long res{1};
    for(auto u:adj[node]){
	if(visited[u]!=-1)continue;
	res+=dfs(u,adj,visited,id);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    //the problem is asking me to check if every connected 
    //compoenent has size 3
    //but there is smth fishy with the time constraint
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
	int a,b;
	cin>>a>>b;
	adj[--a].push_back(--b);
	adj[b].push_back(a);
    }
    vector<int>visited(n,-1);
    vector<int>size(n,1);
    vector<int>one;
    vector<int>two;
    vector<int>three;
    for(int i=0;i<n;i++){
	if(-1==visited[i]){
	    int s;
	    if((s=dfs(i,adj,visited,i))>3){
		cout<<-1;
		return 0;
	    }
	    size[i]=s;
	    if(size[i]==3){
		three.push_back(i);
	    }else if(size[i]==2){
		two.push_back(i);
	    }else{
		one.push_back(i);
	    }
	}
    }
    if(two.size()>one.size()){
	cout<<-1;
	return 0;
    }
    for(auto i:three){
	for(int j=0;j<n;j++){
	    if(visited[j]==i){
		cout<<j+1<<' ';
	    }
	}
	cout<<'\n';
    }
    for(int i=0;i<two.size();i++){
	for(int j=0;j<n;j++){
	    if(visited[j]==two[i]){
		cout<<j+1<<' ';
	    }
	}
	cout<<one[i]+1;
	cout<<'\n';
    }
    int count{};
    for(int i=two.size();i<one.size();i++){
	cout<<one[i]+1<<' ';
	count++;
	if(count%3==0){
	    cout<<'\n';
	}
    }
    return 0;
}

// 6 4 1 2 2 3 3 4 5 6
// 3 0
// 3 3 1 2 2 3 1 3
//
//6 3 1 2 3 4 5 6
