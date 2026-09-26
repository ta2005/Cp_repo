#include <bits/stdc++.h>
#include <fstream>

using namespace std;


int main() {
    ifstream in("revegetate.in");
    ofstream out("revegetate.out");
    int n, m;
    in >> n >> m;
    vector<vector<pair<int, char>>> adj(n);
    for (int i = 0; i < m; i++) {
        char s;
        int a, b;
        in >> s >> a >> b;
        --a;
        --b;
        adj[a].push_back({b, s});
        adj[b].push_back({a, s});
    }
    vector<int> visisted(n, -1);
    int components = 0;
    queue<int> q;
    bool poss = true;
    auto bfs = [&](int x) {
        q.push(x);
        visisted[x] = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto [u, s] : adj[curr]) {
                if (visisted[u] != -1) {
                    if (s == 'S' && visisted[u] != visisted[curr]) {
                        poss = false;
                        return;
                    } else if (s == 'D' && visisted[u] != (1 - visisted[curr])) {
                        poss = false;
                        return;
                    }
                } else {
                    if (s == 'S') {
                        visisted[u] = visisted[curr];
                    } else {
                        visisted[u] = 1 - visisted[curr];
                    }
		    q.push(u);
                }
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (visisted[i] == -1) {
            bfs(i);
            components++;
            if (!poss) {
                out << 0 << '\n';
                return 0;
            }
        }
        // each connected comp can have one of two colors
    }
    out << 1;
    for (int i = 0; i < components; i++) {
        out << 0;
    }
    out << "\n";

    return 0;
}
// 3 2 S 1 2 D 3 2
