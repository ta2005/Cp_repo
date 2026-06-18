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
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        // I only need to iterate over the rows than
        // the diagonals
        // my cashe will kill me but it is what it is
        long long res{};
        for (int i = 0; i < ((m + 1) / 2); i++) {
            pair<int, int> count{0, 0};
            for (int j = 0; j < n && (i - j) >= 0; j++) {
                if (v[j][i - j] == 0) {
                    count.first++;
                } else {
                    count.second++;
                }
            }
            pair<int, int> count1{0, 0};
            for (int j = n-1; j >=0  && ((n-1-j)+m-1-i)<m; j--) {
                if (v[j][(n-1-j)+m-1-i] == 0) {
                    count1.first++;
                } else {
                    count1.second++;
                }
            }
            int a = abs(count1.first - count.first);
            int b = abs(count1.second - count.second);
	    res += abs(a-b);
        }
        cout << res << '\n';
    }
    return 0;
}

// 4 2 2 1 1 0 1 2 3 1 1 0 1 0 0 3 7 1 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 0 1 3
// 5 1 0 1 0 0 1 1 1 1 0 0 0 1 0 0
// 1 2 2 1 1 0 1
// 1 2 3 1 1 0 1 0 0
// 1 3 7 1 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 0 1
