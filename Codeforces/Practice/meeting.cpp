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

pair<double, double> intersect(pair<double, double> r1,
                               pair<double, double> r2) {
    if (r1.second < r2.first || r2.second < r1.first) {
        return {-1.0, -1.0};
    }
    return {max(r1.first, r2.first), min(r1.second, r2.second)};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tr = 1;
    cin >> tr;
    while (tr--) {
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	vector<int>t(n);
	for(int i=0;i<n;i++){
	    cin>>t[i];
	}
	double l=*max_element(t.begin(),t.end());
	// the worst case is getting all the people to hte first square 
	// so this value suffices
	double r=LONG_LONG_MAX;
	auto check=[&](double x) -> pair<bool,double> {
	    pair<double,double> res={LONG_LONG_MIN,LONG_LONG_MAX};
	    for(int i=0;i<n;i++){
		pair<double,double> interval={max(v[i]-(x-t[i]),0.0),v[i]+(x-t[i])};
		res=intersect(res,interval);
		if(res.first==-1.0){
		    return {false,0.0};
		}
	    }
	    return {true,res.first};
	};
	double res{};
	for(int i=0;i<100;i++){
	    double mid=(l+r)/2;
	    auto [status,pos]=check(mid);
	    if(status){
		r=mid;
		res=pos;
	    }else{
		l=mid;
	    }
	}
	cout<<setprecision(9)<<res<<'\n';
    }
    return 0;
}

// 7 1 0 3 2 3 1 0 0 2 1 4 0 0 3 1 2 3 0 0 0 3 1 2 3 4 1 2 3 3 3 3 5 3 3 6 5 4 7 2 10 4 3 2 5 1 4 6
