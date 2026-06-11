#include <bits/stdc++.h>
using namespace std;

struct p {
    int first;
    int second;
    int i;
    bool operator<(const p &a) const { return this->first < a.first; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<p> v(n);
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].i = i;
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    int count{};
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        // binary search for its x;
        // i want to look for the first value that is >=
        // so lower bound
        auto it = lower_bound(v.begin(), v.end(), x,
                              [](auto a, auto b) { return a.first < b; });
        if (it != v.end()) {
            // i look the one before it
            int index = it - v.begin();
            long long dis =
                (x - v[index].first) * (x - v[index].first) + (y) * (y);
            if (dis <= v[index].second * v[index].second) {
                if (res[v[index].i] == -1) {
                    res[v[index].i] = 1 + i;
                    count++;
                }
            }
        }
        if (it != (v.begin())) {
            int index = ((it)-v.begin()) - 1;
            long long dis =
                (x - v[index].first) * (x - v[index].first) + (y) * (y);
            if (dis <= v[index].second * v[index].second) {
                if (res[v[index].i] == -1) {
                    res[v[index].i] = 1 + i;
                    count++;
                }
            }
        }
    }
    cout << count << '\n';
    for (auto i : res) {
        cout << i << ' ';
    }
    return 0;
}
// 3 2 1 5 2 10 1 5 0 1 1 3 3 0 4 0 4 0
// 3 -3 3 -10 2 10 2 4 10 2 2 -2 -11 -1 10 0
