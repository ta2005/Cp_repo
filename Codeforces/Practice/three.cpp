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

namespace rg = std::ranges;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> a(n);
        vector<pii> b(n);
        vector<pii> c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].fi;
            a[i].se = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].fi;
            b[i].se = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i].fi;
            c[i].se = i;
        }
        rg::sort(a, greater());
        rg::sort(b, greater());
        rg::sort(c, greater());
        int res{};
	for(int i=0;i<3;i++){
	    for(int j=0;j<3;j++){
		for(int k=0;k<3;k++){
		    if(a[i].se==b[j].se || b[j].se==c[k].se || a[i].se==c[k].se ) continue;
		    res=max(res,a[i].fi+b[j].fi+c[k].fi);
		}
	    }
	}
	cout<<res<<endl;
    }
    return 0;
}

// 4 3 1 10 1 10 1 1 1 1 10 4 30 20 10 1 30 5 15 20 30 25 10 10 10 5 19 12 3 18 18 6 17 10 13 15 17 19 11 16 3 11 17 17 17 1 17 18 10 15 8 17 3 13 12 10 17 5 4 18 12 4 11 2 16 16 8 4 14 19 3 12 6 7 5 16 3 4 8 11 10 8 10 2 20 3
//1 10 5 19 12 3 18 18 6 17 10 13 15 17 19 11 16 3 11 17 17 17 1 17 18 10 15 8 17 3 13 12
