#include <bits/stdc++.h>
using namespace std;

double acc{};
int nbr_ends{};

void dfs(int node,int parent,vector<vector<int>>&v,vector<int>&dis,double prob){
    if(v[node].size()==1){
	// printf("reachind node %d with prob %f\n",node,prob);
	acc+=dis[node]*prob;
    }
    for(auto u:v[node]){
	if(u==parent)continue;
	dis[u]=dis[node]+1;
	dfs(u,node,v,dis,prob/(v[node].size()-1));
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>>v(n+1);
    v[1].push_back(-1);
    for(int i=0;i<n-1;i++){
	int a,b;
	cin>>a>>b;
	v[a].push_back(b);
	v[b].push_back(a);
    }
    vector<int>dis(n+1);
    dfs(1,-1,v,dis,1.0);
    printf("%.7f",(double)acc);

    return 0;
}
