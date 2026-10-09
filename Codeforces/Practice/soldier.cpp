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

vector<int> sieve(int n) {
    vector<int> is_prime(n + 1);
    vector<int> spf(n + 1);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (int j = i * i; j <= n; j += i) {
                spf[j] = i;
            }
        }
    }
    vector<int> res(n + 1);
    vector<int> pref(n + 2);
    for (int i = 2; i < n + 1; i++) {
        if (spf[i] == i) {
            res[i] = 1;
        } else {
            res[i] = res[i / spf[i]] + 1;
        }
    }
    for (int i = 2; i < n + 1; i++) {
        pref[i + 1] = pref[i] + res[i];
    }
    return pref;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    auto pref = sieve(6 * 1e6);
    while (t--) {
        int a, b;
        cin >> a >> b;
	cout<<pref[a+1]-pref[b+ 1]<<endl;
	// for(int i=b+1;i<=a;i++){
	//     cout<<i<<' ' << pref[i]<<endl;
	// }
        // a++;
        // b++;
        // cout << pref[a] - pref[b] << endl;
    }
    return 0;
}
