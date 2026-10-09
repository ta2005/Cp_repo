#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl "\n"
#define int long long
typedef long long ll;

struct lab {
    int a, b, c;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<lab> v(n);
        int m = LLONG_MAX;

	for (int i = 0; i < n; i++) {
            cin >> v[i].a >> v[i].b >> v[i].c;
            m = min(m, v[i].a + v[i].b + v[i].c);
        }

        auto check = [&](int T) {
            int total_cost = 0;
            for (const auto &L : v) {
                int S = L.a + L.b + L.c;
                if (T <= S)
                    continue;

                if (L.a == L.b && L.b == L.c)
                    return false;

                int overhead = 0;
                if (L.a > L.b || L.a > L.c || L.b > L.c) {
                    overhead = 0;
                } else if (L.a < L.b && L.b < L.c) {
                    overhead = 4;
                } else { 
                    overhead = 2;
                }

                int cost = (T - S) + overhead;
                if (k - total_cost < cost)
                    return false;

                total_cost += cost;
            }
            return total_cost <= k;
        };

        int l = m;
        int r = (LLONG_MAX - m <k)?LLONG_MAX:m+k;
        int ans = m;

        while (l <= r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1; 
            } else {
                r = mid - 1; 
            }
        }

        cout << ans << endl;
    }
    return 0;
}
