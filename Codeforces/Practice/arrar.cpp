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

vector<int> sieve(int n){
    vector<bool>is_prime(n+1,true);
    is_prime[1]=false;
    is_prime[0]=false;
    vector<int>primes;
    for(int i=2;i<=n;i++){
	if(is_prime[i]){
	    primes.pb(i);
	    for(int j=i*i;j<=n;j+=i){
		is_prime[j]=false;
	    }
	}
    }
    return primes;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    auto s=sieve(1e3);
    while (t--) {
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	int m=LONG_LONG_MAX;
	for(auto p:s){
	    for(int i=0;i<n;i++){
		if(v[i]%p!=0){
		    m=min(m,p);
		    break;
		}
	    }
	}
	cout<<m<<endl;
    }
    return 0;
}

// 4 1 1 4 6 6 12 12 3 24 120 210 4 2 4 6 10
