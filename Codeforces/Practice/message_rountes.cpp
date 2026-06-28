#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
	int a,b;
	cin>>a>>b;
	--a;--b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    vector<int>distance(n,-1);
    vector<int>prev(n,-1);
    queue<int>q;
    q.push(0);
    distance[0]=1;
    while(!q.empty()){
	int u=q.front();q.pop();
	for(auto node:adj[u]){
	    if(distance[node]!=-1)continue;
	    distance[node]=distance[u]+1;
	    q.push(node);
	    prev[node]=u;
	}
    }
    if(distance[n-1]==-1){
	cout<<"IMPOSSIBLE\n";
	return 0;
    }
    vector<int>res;
    int node=n-1;
    for(int i=0;i<distance[n-1];i++){
	res.push_back(node);
	node=prev[node];
    }
    reverse(res.begin(),res.end());
    cout<<distance[n-1]<<'\n';
    for(auto i:res){
	cout<<i+1<<' ';
    }
    return 0;
}
// 5 5 1 2 1 3 1 4 2 3 5 4
