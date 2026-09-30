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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vector<int>> v(n, vector<int>(m));
        vector<int> col(n);
        vector<int> rows(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                rows[j] += v[i][j];
                col[i] += v[i][j];
            }
        }
        pii p{};
        for (int i = 0; i < (int)s.size(); i++) {
            // cout<<p.fi<<' '<<p.se<<endl;
            if (s[i] == 'D') {
                int x = -col[p.first];
                v[p.fi][p.se] = x;
                rows[p.second] += x;
                p = {p.fi + 1, p.se};
            } else {
                int x = -rows[p.second];
                v[p.fi][p.se] = x;
                col[p.first] += x;
                p = {p.fi, p.se + 1};
            }
        }
        int x = -col[p.first];
        v[p.fi][p.se] = x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

// 4 3 3 DRRD 0 2 3 0 0 0 3 1 0 4 5 DRRRRDD 0 1 0 2 3 0 0 0 0 0 -1 0 -3 -3 0 0 0
// 0 -1 0 2 3 RRD 0 0 0 0 1 0 5 5 DDDDRRRR 0 25 2 9 11 0 6 13 20 22 0 17 24 1 8
// 0 3 10 12 19 0 0 0 0 0
