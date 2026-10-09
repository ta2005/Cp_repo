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
    while (t--) {
        int n, x, m;
        cin >> x >> n >> m;
        int a = x;
        int org_n = n;
        int org_m = m;
        int prev = a;
        while (a != 0 && (n + m != 0)) {
            if (a % 2 == 0) {
                if (m != 0) {
                    a /= 2;
                    m--;
                } else if (n != 0) {
                    a /= 2;
                    n--;
                }
            } else {
                if (n != 0) {
                    a /= 2;
                    n--;
                } else if (m != 0) {
                    a /= 2;
                    a++;
                    m--;
                    if (a == prev) {
                        m = 0;
                    }
                }
            }
            prev = a;
        }
        cout << a << ' ';
        a = x;
	prev=a;
        n = org_n;
        m = org_m;
        while (a != 0 && (n + m != 0)) {
            if (a % 2 == 0) {
                if (n != 0) {
                    a /= 2;
                    n--;
                } else if (m != 0) {
                    a /= 2;
                    m--;
                }
            } else {
                if (m != 0) {
                    a /= 2;
                    m--;
                    a++;
                    if (a == prev) {
                        m = 0;
                    }
                } else if (n != 0) {
                    a /= 2;
                    n--;
                }
            }
	    prev=a;
        }
        cout << a << endl;
    }
    return 0;
}

// 5 12 1 2 12 1 1 12 0 0 12 1000000000 1000000000 706636307 0 3
