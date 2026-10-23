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
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }
    void update(int u, int k) {
        u += sz;
        t[u] = k;
        for (u /= 2; u >= 1; u /= 2) {
            t[u] = t[2 * u] + t[2 * u + 1];
        }
    }
    long long ask(int a, int b) {
        a += sz;
        b += sz;
        long long s = 0;
        while (a <= b) {
            if (a % 2 == 1)
                s += t[a++];
            if (b % 2 == 0)
                s += t[b--];
            a /= 2;
            b /= 2;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto st = SegTree(v);
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                int k, u;
                cin >> k >> u;
                --k;
                st.update(k, u);
            }; break;
            case 2: {
                int a, b;
                cin >> a >> b;
                --a;
                --b;
                cout << st.ask(a, b) << '\n';
            }
        }
    }
    return 0;
}
// 8 4 3 2 4 5 1 1 5 3
