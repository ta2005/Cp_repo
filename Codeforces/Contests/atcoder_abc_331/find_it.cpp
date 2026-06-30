#include <bits/stdc++.h>
using namespace std;

int start = -1;

void dfs(int node, vector<vector<int>> &adj, vector<bool>&visited) {
    visited[node] = true;
    for (auto u : adj[node]) {
        if (visited[u]) {
            if (start == -1) {
                start = u;
                return;
            }
        }
        dfs(u, adj, visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
	--a;
	v[i]=a;
        adj[i].push_back(a);
    }
    vector<bool>visited(n);
    dfs(0,adj,visited);
    int next=v[start];
    vector<int>res;
    res.push_back(next);
    while(next!=start){
	next=v[next];
	res.push_back(next);
    }
    cout<<res.size()<<'\n';
    for(auto i:res){
	cout<<i+1<<' ';
    }
    return 0;
}
