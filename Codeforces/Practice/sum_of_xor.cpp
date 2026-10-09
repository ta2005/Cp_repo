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
    constexpr int mod=998244353;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
	int n;
	cin>>n;
	vector<int>v(n);
	int res{};
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	for(int i=0;i<31;i++){
	    vector<int>xr(n);
	    vector<int>pref_xr(n+1);
	    for(int j=0;j<n;j++){
		xr[j]=(v[j]&(1<<i))>>i;
	    }
	    for(int j=0;j<n;j++){
		pref_xr[j+1]=pref_xr[j]^xr[j];
	    }
	    // I will need to search for interval 
	    // l and r such that the sum of 1 bit is odd 
	    // aka it's xor is one (if it starts with zero)
	    // or zero if it starts with zero
	    int count0{1};
	    int count1{};
	    int sum0{};
	    int sum1{};
	    int acc{};
	    for(int j=1;j<=n;j++){
		if(pref_xr[j]==0){
		    count0++;
		    sum0+=j;
		    acc+=j*count1-sum1;
		}else{
		    count1++;
		    sum1+=j;
		    acc+=j*count0-sum0;
		}
		acc%=mod;
	    }
	    res+=(((acc<<i))%mod);
	    res%=mod;
	}
	cout<<res<<endl;
    }
    return 0;
}

// 3 1 3 2
// 0  1  1  1  0  0  1  1  0  0
// 0  1   0  1 1  1  0  1  1  1
