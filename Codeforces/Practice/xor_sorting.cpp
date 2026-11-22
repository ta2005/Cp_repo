// CP Template{{{
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
#define debug(a) for(auto &i:a) cout<<i<<" "; cout<<endl;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
[[maybe_unused]]constexpr double EPS=numeric_limits<double>::epsilon();
using clk = chrono::high_resolution_clock;
// }}}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
	int n,q;
	cin>>n>>q;
	vector<int>v(n);
	// the indecies are connnected by edges
	// that represent an exchange 
	// whch defines a cycle
	// and i need to find the min xor 
	// in that cycle
	ordered_set<int>s;
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    s.insert(v[i]);
	}
	int res{};
	vector<pii>ex;
	for(int i=0;i<n;i++){
	    int ord=s.order_of_key(v[i]);
	    if(i!=ord){
		ex.pb({i,ord});
	    }
	}
	println("{}",ex);
	// cout<<res<<endl;
    }
    return 0;
}

// 3 3 0 2 3 4 2 0 1000000000 999999999 6 0 2 5 3 4 1 6
