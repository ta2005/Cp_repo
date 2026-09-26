#include <bits/stdc++.h>

using namespace std;

vector<int> tin;
// this is the first time we exited node i
vector<int> tout;
int timer;
constexpr int l = 21;
vector<vector<int>> up;
vector<vector<int>> adj;

auto dfs(int x, int p) -> void {
    tin[x] = ++timer;
    up[x][0]=p;
    for (int i = 1; i <= l; i++) {
        up[x][i] = up[up[x][i - 1]][i - 1];
    }
    for (auto u : adj[x]) {
        if (u != p) {
            dfs(u, x);
        }
    }
    tout[x]=++timer;
};

bool is_ancestor(int u,int v){
    return tin[u]<=tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[0].push_back(0);
    tin.resize(n);
    tout.resize(n);
    up.assign(n, vector<int>(l + 1));
    dfs(0,0);
    int q;
    cin>>q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
    }
}


// 5 1 2 2 3 3 4 3 5 3 2 2 5 3 3 3
