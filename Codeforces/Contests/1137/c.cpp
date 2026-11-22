// CP Template{{{
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl "\n"
#define int long long
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes cout << "YES\n";
#define m1 cout << "-1\n";
#define no cout << "NO\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int64_t i64;
#define debug(a)                                                               \
    for (auto &i : a)                                                          \
        cout << i << " ";                                                      \
    cout << endl;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
[[maybe_unused]] constexpr double EPS = numeric_limits<double>::epsilon();
using clk = chrono::high_resolution_clock;
// }}}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            pos[v[i]] = i;
        }
        int res = n * (n + 1) / 2;
        set<int> curr;
        for (int i = 1; i <= n; i++) {
            auto it = curr.lower_bound(pos[i]);
            int L = (it == curr.begin()) ? -1 : *prev(it);
            int R = (it == curr.end()) ? n : *it;
            res -= (pos[i] - L - 1) * (R - pos[i] - 1);
            curr.insert(pos[i]);
        }
        cout << res << endl;
        // for each element i need to see its bounds
        // the first element smaller to its right and left
        // and subtract (pos+1)*(end-pos)-2 from res
    }
    return 0;
}

// 4 1 1 2 1 2 4 3 2 4 1 7 3 7 5 1 6 4 2
