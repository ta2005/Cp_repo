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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        // for bob the optimal strategy is to alway take the same nbr as alex if
        // possible
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            freq[v[i]]++;
        }
	// this tracks whetehr bob can win
        bool test = true;
        int prev = -1;
        for (auto [u, f] : freq) {
            if (u != (prev + 1)) {
                // this means that no matter what happens bob wins
                test = true;
                break;
            }
            if (f < 2 * k) {
		if(f==(2*k-1)){
		    test = false;
		}else{
		    test = true;
		}
                break;
            }
	    prev=u;
        }
        cout << (!test ? "YES\n" : "NO\n");
    }
    return 0;
}

// 5 4 1 2 0 0 1 4 1 0 1 0 1 6 2 1 2 0 1 0 0 6 2 0 0 1 1 2 2 8 2 0 1 1 0 0 2 0 1
