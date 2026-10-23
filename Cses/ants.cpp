#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    vector<long long> t;
    int sz;
    SegTree(vector<int> &w) {
        int n = w.size();
        sz = n;
        t.assign(2 * sz, 0);
        for (int i = 0; i < n; i++) {
            t[sz + i] = w[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            t[i] = gcd(t[2 * i], t[2 * i + 1]);
        }
    }
    void update(int u, int k) {
        u += sz;
        t[u] = k;
        for (u /= 2; u >= 1; u /= 2) {
            t[u] = gcd(t[2 * u], t[2 * u + 1]);
        }
    }
    long long ask(int a, int b) {
        a += sz;
        b += sz;
        long long s = 0;
        while (a <= b) {
            if (a % 2 == 1)
                s = gcd(t[a++], s);
            if (b % 2 == 0)
                s = gcd(t[b--], s);
            a /= 2;
            b /= 2;
        }
        return s;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        w[i] = {v[i], i};
    }
    sort(w.begin(), w.end());
    SegTree st = SegTree(v);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int pgcd = st.ask(l, r);
        pair<int, int> search = {pgcd, l};
        auto [it1, it2] =
            equal_range(w.begin(), w.end(), search,
                        [](const pair<int, int> &a, const pair<int, int> &b) {
                            return a.first < b.first;
                        });
        if (it1 == it2 || it1->first != pgcd) {
	    cout<<r-l+1<<'\n';
        } else {
            auto it3 = lower_bound(
                it1, it2, search,
                [](const pair<int, int> &a, const pair<int, int> &b) {
                    return a.second < b.second;
                });
            search = {pgcd, r};
            auto it4 = upper_bound(
                it1, it2, search,
                [](const pair<int, int> &a, const pair<int, int> &b) {
                    return a.second < b.second;
                });
            cout << r-l+1-(it4 - it3) <<'\n';
        }
    }
    return 0;
}
