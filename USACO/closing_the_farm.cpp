#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>&closed, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = true;
    for (auto u : adj[node]) {
	if (visited[u] || closed[u])
	    continue;
	dfs(u, closed, adj, visited);
    }
}

int main() {
    auto in=ifstream("closing.in");
    auto out=ofstream("closing.out");
    ios::sync_with_stdio(false);
    in.tie(0);
    int n, m;
    in >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; i++) {
	int a, b;
	in >> a >> b;
	v[--a].push_back(--b);
	v[b].push_back(a);
    }

    vector<bool>closed(n);
	//    dfs(0, closed, v, visited);
	//    bool test = true;
	//    for (int i = 0; i < n; i++) {
	// if (!visited[i]) {
	//     test = false;
	//     break;
	// }
	//    }
	//    if (test) {
	// out << "YES\n";
	//    } else {
	// out << "NO\n";
	//    }
    for(int j=0;j<n;j++){
	vector<int> visited(n);
	for (int i = 0; i < n; i++) {
	    if (!visited[i] && !closed[i]) {
		dfs(i, closed, v, visited);
		break;
	    }
	}
	bool test = true;
	for (int i = 0; i < n; i++) {
	    if (closed[i])
		continue;
	    if (!visited[i]) {
		test = false;
		break;
	    }
	}
	if (test) {
	    out << "YES\n";
	} else {
	    out << "NO\n";
	}
	int skip;
	in>>skip;
	closed[--skip]=true;
    }

    return 0;
}
// 4 3 1 2 2 3 3 4 3 4 1 2
