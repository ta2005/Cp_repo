#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // every node is in reality three nodes
    // one for each mod 3 to get there
    // so my distance (this is bfs to minimize the distance)
    //	is a vector of three dimentions one for 
    //	0 1 2 the mod of three
    //	or at least i think so
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
	int a,b;
	cin>>a>>b;
	--a;--b;
	adj[a].push_back(b);
    }
    int s,t;
    cin>>s>>t;
    --s;--t;
    vector<vector<int>>dis(n,vector<int>(3,-1));
    queue<pair<int,int>>q;
    q.push({s,0});
    dis[s][0]=0;
    while(!q.empty()){
	auto [node,mod] = q.front();q.pop();
	int next_mod=(mod+1+3)%3;
	for(auto i:adj[node]){
	    if(dis[i][next_mod]!=-1)continue;
	    q.push({i,next_mod});	
	    dis[i][next_mod]=dis[node][mod]+1;
	}
    }
    if(dis[t][0]!=-1){
	dis[t][0]/=3;
    }
    cout<<dis[t][0];
    return 0;
}

// 4 4 1 2 2 3 3 4 4 1 1 3
