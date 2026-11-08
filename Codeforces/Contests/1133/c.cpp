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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
	vector<int> diff(n-1);
	for(int i=0;i<(n-1);i++){
	    diff[i]=abs(v[i]-v[i+1]);
	}
	vector<int>suff(n+2);
	vector<int>pref(n+1);
	for(int i=0;i<(n-1);i++){
	    pref[i+1]=max(pref[i],diff[i]);
	}
	for(int i=n-2;i>=0;i--){
	    suff[i]=max(suff[i+1],diff[i]);
	}
	int m = pref[n - 1];
	int pos = 0;
	for (int i = 0; i + 1 < n; i++) {
	    if (diff[i] == m) { 
		pos = i; break; 
	    }
	}
	int res=m;
	// the idea is that we need to mazimaze
	// the max diff
	// it comes from pos and pos+1
	// so we try and inverst from pos+1 ... till hte end
	// and from pos going backward
        {
            int l = pos + 1;
            int inside = 0; 
            for (int r = l; r < n; r++) {
                if (r > l) inside = max(inside, diff[r - 1]);
                int cur = pref[pos];                           
		// when flipping we get pos to face the farthest point
                cur = max(cur, abs(v[pos] - 2 * v[r]));     
                cur = max(cur, 2 * inside);
                if (r < n - 1) cur = max(cur, abs(2 * v[l] - v[r + 1])); 
		// these are for the one after 
                cur = max(cur, suff[r + 1]);                   
                res = min(res, cur);
            }
        }
        {
            int r = pos;
            int inside = 0;  
            for (int l = r; l >= 0; l--) {
                if (l < r) inside = max(inside, diff[l]);
                int cur = 0;
                if (l > 0) {
                    cur = max(cur, abs(v[l - 1] - 2 * v[r])); 
                    cur = max(cur, pref[l - 1]);                 
                }
                cur = max(cur, abs(2 * v[l] - v[r + 1]));     
                cur = max(cur, 2 * inside);
                cur = max(cur, suff[r + 1]);                     
                res = min(res, cur);
            }
        }
	cout<<res<<endl;
    }
    return 0;
}

// 6 9 9 9 8 2 4 4 3 5 3 2 5 6 5 1 7 4 1 10 2 10 16 5 5 2 6 5 3 6 8 3 9 9 9 8
