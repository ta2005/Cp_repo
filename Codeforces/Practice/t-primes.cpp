// CP Template{{{
#include <bits/stdc++.h>
#include <cmath>
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
    auto s=sieve(1e6+5);
    set<int> st(s.begin(),s.end());
    // cin >> t;
    while (t--) {
	int n;
	cin>>n;
	vector<int>v(n);
	vector<bool>res(n);;
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	for(int i=0;i<n;i++){
	    int r=sqrtl(v[i]);
	    if(r*r==v[i]){
		res[i]=st.count(r)!=0;
	    }
	}
	for(auto i:res){
	    cout<<(i?"YES\n":"NO\n");
	}
    }
    return 0;
}
