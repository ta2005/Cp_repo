// CP Template{{{
#include <bit>
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
    // cin >> t;
    while (t--) {
	int n,k;
	cin>>n>>k;
	int nbr=popcount(static_cast<unsigned long long>(n));
	if(k<nbr || k > n ){
	    cout<<"NO\n";
	    continue;
	}
	cout<<"YES\n";
	int rest{nbr};
	for(int i=0;i<30;i++){
	    if((n&(1<<i))!=0){
		if(k==rest){
		    cout<<(1<<i)<<' ';
		    k--;
		}else{
		    int sur=k-rest;
		    int to_use=min(sur+1,(1LL<<i));
		    int base=1LL<<i;
		    for(int x=1;x<30;x++){
			int upper=1<<x;
			int lower=(1<<(x-1))+1;
			if(to_use >= lower && to_use <= upper){
			    base/=(1<<x);
			}
		    }
		    int nbr_low=2*to_use-(1LL<<i)/base;
		    int nbr_high=to_use-nbr_low;
		    for(int j=0;j<nbr_low;j++){
			cout<<base<<' ';
		    }
		    for(int j=0;j<nbr_high;j++){
			cout<<base*2<<' ';
		    }
		    k-=to_use;
		}
		rest--;
	    }
	}
	cout<<endl;
    }
    return 0;
}
