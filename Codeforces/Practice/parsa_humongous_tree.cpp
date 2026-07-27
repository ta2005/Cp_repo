#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // for each node it is best to choose
        // either its max or minimum
        vector<vector<long long>> dp(2, vector<long long>(n));
        adj[0].push_back(-1);
        std::function<void(int, int)> dfs = [&](int node, int parent) {
            for (auto u : adj[node]) {
                // this should not happen the graph is directed
                if (u == parent)
                    continue;
                dfs(u, node);
            }
            // after the leafs have been process
            // after the leafs have been processed
            if (parent != -1) {
                // Parent chooses its minimum (v[parent].first)
                long long option1 =
                    dp[0][node] + abs(v[node].first - v[parent].first);
                long long option2 =
                    dp[1][node] + abs(v[node].second - v[parent].first);
                dp[0][parent] += max(option1, option2);

                // Parent chooses its maximum (v[parent].second)
                long long option3 =
                    dp[0][node] + abs(v[node].first - v[parent].second);
                long long option4 =
                    dp[1][node] + abs(v[node].second - v[parent].second);
                dp[1][parent] += max(option3, option4);
            }
        };
        dfs(0, -1);
        cout << max(dp[0][0], dp[1][0]) << '\n';
    }

    return 0;
}

// 3 2 1 6 3 8 1 2 3 1 3 4 6 7 9 1 2 2 3 6 3 14 12 20 12 19 2 12 10 17 3 17 3 2 6 5 1 5 2 6 4 6
// 1 6 3 14 12 20 12 19 2 12 10 17 3 17 3 2 6 5 1 5 2 6 4 6
