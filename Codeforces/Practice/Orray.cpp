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
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
	vector<bool>used(n);
	int curr_or=0;
	for(int i=0;i<31;i++){
	    int mx=0;
	    int idx=-1;
	    for(int j=0;j<n;j++){
		if(used[j])continue;
		if((curr_or|v[j])>mx){
		    mx=v[j]|curr_or;
		    idx=j;
		}
	    }
	    if(idx==-1)continue;
	    used[idx]=true;
	    cout<<v[idx]<<' ';
	    curr_or|=v[idx];
	}
	for(int i=0;i<n;i++){
	    if(used[i])continue;
	    cout<<v[i]<<' ';
	}
        cout << endl;
    }
    return 0;
}
// 5 4 1 2 4 8 7 5 1 2 3 4 5 5 2 1 101 6 2 3 4 2 3 4 8 1 4 2 3 4 5 7 1
// 1 7 5 1 2 3 4 5 5
