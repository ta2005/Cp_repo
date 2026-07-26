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
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<vector<int>> dp(2, vector<int>(n+1, INT_MAX));
        dp[0][0] = v[0];
        for (int i = 1; i < n; i++) {
            // If it is the friend's turn starting at boss i (and it's a
            // reachable state)
            if (dp[0][i] != INT_MAX) {
                // Friend fights 1 boss (boss i)
                if (i + 1 <= n) {
                    dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + v[i]);
                }
                // Friend fights 2 bosses (boss i and i+1)
                if (i + 2 <= n) {
                    dp[1][i + 2] =
                        min(dp[1][i + 2], dp[0][i] + v[i] + v[i + 1]);
                }
            }

            // If it is your turn starting at boss i (and it's a reachable
            // state)
            if (dp[1][i] != INT_MAX) {
                // You fight 1 boss (cost is 0)
                if (i + 1 <= n) {
                    dp[0][i + 1] = min(dp[0][i + 1], dp[1][i]);
                }
                // You fight 2 bosses (cost is 0)
                if (i + 2 <= n) {
                    dp[0][i + 2] = min(dp[0][i + 2], dp[1][i]);
                }
            }
        }
        // d[i] is the min nbr of coins needed to reach boss i
        cout << min(dp[0][n-1],dp[1][n-1])<<'\n';
    }

    return 0;
}

// 6 8 1 0 1 1 0 1 1 1 5 1 1 1 1 0 7 1 1 1 1 0 0 1 6 1 1 1 1 1 1 1 1 1 0
