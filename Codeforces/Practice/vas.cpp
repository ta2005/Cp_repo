#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pref(n + 1);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        pref[i + 1] = pref[i];
        if (c == 'a') {
            pref[i + 1].first++;
        } else {
            pref[i + 1].second++;
        }
    }
    int res{0};
    int l = 0, r = 0;
    while (r <= n) {
        int a = pref[r].first - pref[l].first;
        int b = pref[r].second - pref[l].second;
        if ((a >= b && b <= k) || (b > a && a <= k)) {
            res = max(res, r - l);
            r++;
        } else {
            l++;
        }
    }
    cout << res;
    return 0;
}
// 4 2 abba
