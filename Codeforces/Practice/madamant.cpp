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
	int n; cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	if(n==1){
	    cout<<0<<endl;
	    continue;
	}
	ranges::sort(v,greater());
	vector<int>dp(n);
	int sum{v[0]+v[1]};
	dp[1]=v[0]-v[1];
	constexpr int mod=998244353;
	// this will grow in n!
	int nbr_cases{1};
	for(int i=2;i<n;i++){
	    // we mult by i beacuse we will be inserting v[i]
	    // at every pos
	    int sums=(sum-i*v[i]);
	    // println("nbr_cases {}",nbr_cases);
	    sums=(sums%mod+mod)%mod;
	    // println("sums {}",sums);
	    dp[i]=dp[i-1]*i+sums*nbr_cases;
	    dp[i]%=mod;
	    sum+=v[i];
	    sum%=mod;
	    nbr_cases*=i;
	    nbr_cases%=mod;
	    // println("dp {}",dp);
	}
	dp[n-1]%=mod;
	cout<<dp[n-1]<<endl;
    }
    return 0;
}
// 5 1 10 3 1 2 3 4 4 1 3 2 2 1 1000000000 5 2 7 1 10 4
