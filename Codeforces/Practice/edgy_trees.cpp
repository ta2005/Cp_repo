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

int sz = 0;
void dfs(int u, vector<vector<pii>> &adj, vector<bool> &visisted) {
    if (visisted[u])
        return;
    visisted[u] = true;
    sz++;
    for (auto [n, c] : adj[u]) {
        if (c == 1)
            continue;
        dfs(n, adj, visisted);
    }
}

constexpr int mod = 1e9 + 7;

int power(int x, long long n) { // O(log n)
    int ans = 1 % mod;
    while (n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<pii>> adj(n);
        for (int i = 0; i < (n-1); i++) {
            int a, b, x;
            cin >> a >> b >> x;
            adj[--a].pb({--b, x});
            adj[b].pb({a, x});
        }
        vector<bool> visisted(n);
        int res{};
        for (int i = 0; i < n; i++) {
            if (!visisted[i]) {
                dfs(i, adj, visisted);
                res += power(sz, k);
		res%=mod;
                sz = 0;
            }
        }
        int tot = power(n, k);
        int out = (tot - res + mod) % mod;
        cout << out << endl;
    }
    return 0;
}

// 4 4 1 2 1 2 3 1 3 4 1
