#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        auto block = [&](int x, int y) {
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (v[nx][ny] == '.')
                        v[nx][ny] = '#';
                }
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 'B') {
                    block(i, j);
                }
            }
        }
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        auto dfs = [&](auto& self, int x, int y) -> void {
            if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == '#' || vis[x][y]) {
                return;
            }
            vis[x][y] = true;
            self(self, x + 1, y);
            self(self, x - 1, y);
            self(self, x, y + 1);
            self(self, x, y - 1);
        };
        
        if (v[n-1][m-1] != '#') {
            dfs(dfs, n-1, m-1);
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 'G' && !vis[i][j]) ok = false; 
                if (v[i][j] == 'B' && vis[i][j]) ok = false; 
            }
        }
        
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
