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
	string s;
	cin>>s;
	bool t1=false;
	bool t2=false;
	for(int i=1;i<((int)s.size()-1);i++){
	    if(s[i]=='0' && (s[i-1]=='1' && s[i+1]=='1')){
		t1=true;
	    }else if(s[i]=='1' && (s[i-1]=='0' && s[i+1]=='0')){
		t1=true;
	    } else if(s[i]=='0' && (s[i-1]=='0' && s[i+1]=='0')){
		t2=true;
	    }else if(s[i]=='1' && (s[i-1]=='1' && s[i+1]=='1')){
		t2=true;
	    }
	}
	cout<<1+t1+t2<<endl;
    }
    return 0;
}

// 7 001 000 010 00010 100111011 001011010 1111
