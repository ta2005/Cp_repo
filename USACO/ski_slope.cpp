#include <bits/stdc++.h>
using namespace std;

struct waypoint{
    int p,d,e;
};

void dfs(int node,vector<vector<waypoint>>&adj,vector<int>&enj){
    for(auto u:adj[node]){
	enj[u.p]=enj[node]+u.e;
	dfs(u.p,adj,enj);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    //I think one of the tricks is to do a reversed dfs 
    //form the root 1 to the point which are the ends
    vector<vector<waypoint>>adj(n);
    for(int i=1;i<n;i++){
	int pi,di,ei;
	cin>>pi>>di>>ei;
	adj[pi-1].push_back({i,di,ei});
    }
    vector<int>enj(n);
    dfs(0,adj,enj);
    for(auto i:enj){
	cout<<i<<' ';
    }
    //next my job is to do a dfs and the enjoyment of
    //each point is the sum of the enjoyment of each edge
    //about the difficutlty
    //I could make is a linked list to not get MLE
    //but I don't really know 
	//    for(auto u:adj){
	// for(auto v:u){
	//     cout<<v.p<<' ';
	// }
	// cout<<endl;
	//    }

    return 0;
}
// 4 1 20 200 2 30 300 2 10 100
