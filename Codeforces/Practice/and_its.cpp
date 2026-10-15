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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    vector<vector<int>> pref(21, vector<int>(2 * 1e5 + 5));
    for (int b = 0; b < 21; b++) {
        for (int i = 1; i <= 2 * 1e5; i++) {
            pref[b][i + 1] = pref[b][i] + ((i & (1 << b)) != 0);
        }
    }
    while (t--) {
        int l, r;
        cin >> l >> r;
        int res{r - l + 1};
	l++;
	r++;
        for (int i = 0; i < 21; i++) {
            int one = pref[i][r] - pref[i][l - 1];
            int zeros = r - l + 1 - one;
            res = min(res, zeros);
        }
        cout << res << endl;
    }
    return 0;
}
// 5 1 2 2 8 4 5 1 5 100000 200000
