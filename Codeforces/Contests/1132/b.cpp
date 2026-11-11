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
	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	ranges::sort(v);
	vector<int>res;
	res.reserve(n);
	res.pb(v[n-1]);
	// from biggest to smallest
	// these will have no as answer to query
	for(int i=n-k-1;i>=0;i--){
	    res.pb(v[i]);
	}
	// these will have yes
	// from smallest to biggest
	for(int i=n-k;i<=(n-2);i++){
	    res.pb(v[i]);
	}
	int sum=res[0];
	int nbr=1;
	for(int i=1;i<n;i++){
	    if(res[i]*i>=sum){
		nbr++;
	    }
	    sum+=res[i];
	}
	if(nbr==k){
	    cout<<"YES\n";
	    for(auto i:res){
		cout<<i<<' ';
	    }
	    cout<<endl;
	}else{
	    cout<<"NO\n";
	} 
    }
    return 0;
}
// 4 3 1 1 2 3 3 1 5 5 5 3 2 -1 -2 -3 4 3 0 0 10 -10
