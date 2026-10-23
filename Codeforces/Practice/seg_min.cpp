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

struct SegTree{
    vector<int>p;
    SegTree(vector<int>&v){
	int a=1;
	while(a<=(int)(v.size()))a*=2;
	p.resize(2*a);
	p.assign(2*a,LONG_LONG_MAX);
	for(int i=0;i<(int)(v.size());i++){
	    // p[a+i]=v[i];
	    update(i,v[i]);
	}
    }
    void update(int i,int v){
	int prev=v;
	i+=(p.size()/2);
	p[i]=v;
	while(i!=0){
	    i/=2;
	    p[i]=min(p[i],prev);
	}
    }
    int query(int l,int r){

	return 1;

    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
	int n,q;
	cin>>n>>q;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	SegTree a(v);
	println("{}",a.p);

    }
    return 0;
}
// 5 5 5 4 2 3 5

