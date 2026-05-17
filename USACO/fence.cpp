#include <bits/stdc++.h>
using namespace std;

//this problems is of connectivness 
struct cow{
    int x,y;
};

struct fence{
    int min_x{INT_MAX};
    int min_y{INT_MAX};
    int max_x{0};
    int max_y{0};
};
void dfs(int i,vector<vector<int>>&v,vector<bool>&visisted,fence&f,vector<cow>&c){
    for(auto neigh : v[i]){
	if (visisted[neigh]) continue;
	visisted[neigh]=true;
	f.min_x=min(f.min_x,c[neigh].x);
	f.min_y=min(f.min_y,c[neigh].y);
	f.max_x=max(f.max_x,c[neigh].x);
	f.max_y=max(f.max_y,c[neigh].y);
	dfs(neigh,v,visisted,f,c);
    }
}

int main() {
    ifstream in("fenceplan.in");
    int n,m;
    in>>n>>m;
    vector<cow> v(n+1);
    vector<vector<int>>adj(n+1);
    vector<bool> visisted(n+1);
    for (int i=1;i<=n;i++){
	in>>v[i].x>>v[i].y;
    }
    for (int i=0;i<m;i++){
	int a,b;
	in>>a>>b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    int res{INT_MAX};
    for (int j=1;j<=n;j++){
	if (visisted[j]) continue;
	vector<bool> new_visisted=visisted;
	fence f;
	dfs(j,adj,visisted,f,v);
	res=min(res, f.max_x-f.min_x+f.max_y-f.min_y);
    } 
    ofstream out("fenceplan.out");
    out<<res*2;

    return 0;
}
