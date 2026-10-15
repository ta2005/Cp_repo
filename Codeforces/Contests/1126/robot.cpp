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
	int a,b;
	cin>>a>>b;
	// the index a can only go up so we can only visit (a,b) after 
	// a or a+1 move 
	pii curr{};
	for(int i=0;i<a;i++){
	    if(curr.se<=b){
		curr.se++;
	    }else{
		curr.se--;
	    }
	    curr.fi++;
	}
	if(curr.se==b){
	    cout<<a<<"\n";
	}else if(abs(curr.se-b)==1){
	    cout<<a+1<<endl;
	}else{
	    cout<<"-1\n";
	}
    }
    return 0;
}

// 9 0 0 0 1 0 2 1 0 2 1 2 3 5 6 1000 999 1000 1000
