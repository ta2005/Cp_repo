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

struct st{
    int odd=0;
    int even=0;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	vector<int>b(n);
	st oe_a{};
	st oe_b{};
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    if(a[i]%2==1){
		oe_a.odd++;
	    }else{
		oe_a.even++;
	    }
	}
	for(int i=0;i<n;i++){
	    cin>>b[i];
	    if(b[i]%2==1){
		oe_b.odd++;
	    }else{
		oe_b.even++;
	    }
	}
	if(oe_a.odd==oe_b.odd){
	    cout<<"YES\n";
	    continue;
	}
	if(k%2==0){
	    // we can only turn odd into even
	    // we can't turn even into odd
	    if(oe_a.even>oe_b.even){
		cout<<"NO\n";
	    }else{
		cout<<"YES\n";
	    }
	}else{
	    if(oe_a.odd>oe_b.odd){
		// we can only turn even into odd
		cout<<"NO\n";
	    }else{
		cout<<"YES\n";
	    }
	}
    }
    return 0;
}

// 5 3 4 1 2 7 5 3 8 1 1 0 1 1 1 1 0 6 1 0 0 0 0 0 0 1 3 7 15 31 63 2 1000000 999999 1 1000000 1
