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
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll N = n + m + 1;
        vector<ll> as(N), bs(N);
        for (ll i = 0; i < n + m + 1; i++) {
            cin >> as[i];
        }
        for (ll i = 0; i < n + m + 1; i++) {
            cin >> bs[i];
        }

        vector<ll> prefp(N + 1, 0);
        vector<ll> preft(N + 1, 0);
        vector<ll> pref_best(N + 1, 0);
        vector<ll> pref_a(N + 1, 0);
        vector<ll> pref_b(N + 1, 0);
        
        for (ll i = 0; i < N; i++) {
            prefp[i + 1] = prefp[i] + (as[i] > bs[i]);
            preft[i + 1] = preft[i] + (bs[i] > as[i]);
            pref_best[i + 1] = pref_best[i] + max(as[i], bs[i]);
            pref_a[i + 1] = pref_a[i] + as[i];
            pref_b[i + 1] = pref_b[i] + bs[i];
        }

        for (ll i = 0; i < N; i++) {
            // ... [Keep your exact lower_bound logic here for 'in' and 'im'] ...
	    //
            auto itp = lower_bound(prefp.begin(), prefp.begin() + i + 1, n);
            auto itt = lower_bound(preft.begin(), preft.begin() + i + 1, m);
            ll in = N + 1;
            ll im = N + 1;
            if (itp == prefp.begin() + i + 1) {
                itp = lower_bound(prefp.begin() + i + 1, prefp.end(),
                                  n + (as[i] > bs[i]));
                if (itp != prefp.end()) {
                    in = itp - prefp.begin();
                }
            } else {
                in = itp - prefp.begin();
            }
            if (itt == preft.begin() + i + 1) {
                itt = lower_bound(preft.begin() + i + 1, preft.end(),
                                  m + (bs[i] >= as[i]));
                if (itt != preft.end()) {
                    im = itt - preft.begin();
                }
            } else {
                im = itt - preft.begin();
            }
            
            ll pivot = min(in, im);
            ll res = 0;

            res += pref_best[pivot];
            if (i < pivot) {
                // If candidate i was in this zone, remove their contribution
                res -= max(as[i], bs[i]); 
            }

            // 2. Add the forced skills strictly after the pivot
            if (in < im) {
                // Programmers filled up. Everyone after pivot is a Tester (bs)
                res += (pref_b[N] - pref_b[pivot]);
                if (i >= pivot) {
                    res -= bs[i]; 
                }
            } else {
                // Testers filled up. Everyone after pivot is a Programmer (as)
                res += (pref_a[N] - pref_a[pivot]);
                if (i >= pivot) {
                    res -= as[i]; 
                }
            }

            cout << res << " ";
        }
        cout << endl;
    }

    return 0;
}
// 1 1 2 2 1 5 4 5 2 3 1
