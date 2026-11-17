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
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	int res{};
	for(int i=0;i<31;i++){
	    int acc{};
	    for(int j=0;j<n;j++){
		acc+=((v[j]&(1LL<<i))!=0);
	    }
	    res=gcd(res,acc);
	}
	if(res==0){
	    // the array is all zeros 
	    for(int i=1;i<=n;i++){
		cout<<i<<' ';
	    }
	    cout<<endl;
	}else{
	    for(int i=1;i<=res;i++){
		if(res%i==0){
		    cout<<i<<' ';
		}
	    }
	    cout<<endl;
	}
    }
    return 0;
}

// 5 4 4 4 4 4 4 13 7 25 19 6 3 5 3 1 7 1 1 1 5 0 0 0 0 0
