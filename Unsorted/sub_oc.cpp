#include <bits/stdc++.h>
using namespace std;


void dfs(int node,vector<vector<int>>&v,vector<int>&r){
    for(auto u:v[node]){
	dfs(u,v,r);
	r[node]+=r[u]+1;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>>v(n+1);
    for(int i=2;i<=n;i++){
	int a;
	cin>>a;
	v[a].push_back(i);
    }
    vector<int>res(n+1);
    // dfs(1,-1,v,res);

    dfs(1,v,res);
    for(int i=1;i<=n;i++){
	cout<<res[i]<<' '; 
    }
    return 0;
}
// 5 1 1 2 3
