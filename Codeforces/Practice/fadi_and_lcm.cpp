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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
	int x;
	cin>>x;
	int a=1;
	unordered_map<int,int>m;
	for(int i=2;i*i<=x;i++){
	    while(x%i==0){
		m[i]++;
		x/=i;
	    }
	}
	if(x>1){
	    m[x]++;
	}
	vector<pii>res(m.begin(),m.end());
	for(int i=0;i<(int)res.size();i++){
	    res[i]={res[i].fi,binpow(res[i].fi,res[i].se)};
	}
	// for(auto p:m){
	//     if(p.se%2==1){
	// 	res.pb(p.fi);
	//     }
	//     a*=binpow(p.fi,p.se/2);
	// }
	// now this one is apple division 
	// i will have at most 10 elements
	int r1=-1,r2=-1;
	for(int i=0;i<(1<<res.size());i++){
	    int prod1=1,prod2=1;
	    for(int j=0;j<(int)res.size();j++){
		if(i&(1<<j)){
		    prod1*=res[j].se;
		}else{
		    prod2*=res[j].se;
		}
	    }
	    if(r1==-1 || abs(r1-r2)>abs(prod1-prod2)){
		r1=prod1;
		r2=prod2;
	    }
	}
	cout<<max(r1,r2)*a<<' '<<min(r1,r2)*a;
    }
    return 0;
}
