#include <bits/stdc++.h>
using namespace std;
//i will do o(n^2) to create the adjancy list

struct cow{
    int p;
    int x;
    int y;
    long long distance(cow& other){
	return (this->x-other.x)*(this->x-other.x)+ (this->y-other.y)*(this->y-other.y);
    }
};

void dfs(int i,vector<bool>&visited,vector<vector<int>>&v){
    if (visited[i]) return;
    visited[i]=true;
    // cout<<i<<'\n';
    for (auto j:v[i]){
	dfs(j,visited,v);
    }
}

int main() {
    ifstream in("moocast.in");
    int n;
    in>>n;
    vector<cow> v(n);
    for (int i=0;i<n;i++){
	in>>v[i].x>>v[i].y>>v[i].p;
    }
    vector<vector<int>> adj(n);
    for (int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    if (j==i)continue;
	    if (v[i].distance(v[j])<=v[i].p*v[i].p) {
		adj[i].push_back(j);
	    }
	}
    }

    int res{};
    for (int i=0;i<n;i++){
	vector<bool>visited(n);
	dfs(i,visited,adj);
	int count{};
	for (auto j:visited){
	    count+=j;
	}
	res=max(res,count);
    }
    ofstream out("moocast.out");
    out<<res;


    return 0;
}
