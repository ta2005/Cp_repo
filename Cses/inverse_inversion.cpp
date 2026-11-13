// CP Template{{{
#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
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
    // cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> res(n + 1, -1);
        int rest{k};
        for (int i = n; i >= 1; i--) {
            int give = i - 1;
            if (rest > give) {
                // we will need to use
                // max poss for the given nbr
                res[n - i + 1] = i;
                rest -= give;
            } else {
                res[n - rest] = i;
                rest = 0;
            }
            if (rest == 0)
                break;
        }
        int nbr{1};
        for (int i = 1; i <= n; i++) {
            if (res[i] == -1) {
                res[i] = nbr++;
            }
        }
        //       do {
        //    int nbr{};
        //    for(int i=0;i<n;i++){
        // for(int j=i+1;j<n;j++){
        //     nbr+=v[i]>v[j];
        // }
        //    }
        //    if(nbr==k)break;
        //       } while (next_permutation(all(v)));
        for (int i = 1; i <= n; i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
