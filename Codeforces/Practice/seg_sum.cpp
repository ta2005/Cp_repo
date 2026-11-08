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
    // this should be a template ye bhim
    vector<int>p;
    SegTree(vector<int>&v){
	int size{1};
	while(size<=(int)v.size()){
	    size*=2;
	}
	size*=2;
	p.resize(size);
	for(int i=0;i<(int)v.size();i++){
	    update(i,v[i]);
	}
    }
    void update(int i,int v){
	i+=p.size()/2;
	int to_add=v-p[i];
	p[i]=v;
	while(i>0){
	    i/=2;
	    p[i]+=to_add;
	}
    }
    int query(int l,int r){
	int res{};
	l+=p.size()/2;
	r+=p.size()/2;
	while(l<=r){
	    if(l%2==1)res+=p[l++];
	    if(r%2==0)res+=p[r--];
	    l/=2;
	    r/=2;
	}
	return res;
    }
};

int32_t main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
	int n,m;
	cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	SegTree tr(v);
	// println("{}",tr.p);
	while(m--){
	    int op,l,r;
	    cin>>op>>l>>r;
	    switch(op){
		case 1:
		    tr.update(l,r);
		    break;
		default:
		    r--;
		    cout<<tr.query(l,r)<<endl;
	    }
	}
    }
    return 0;
}

// 5 5 5 4 2 3 5 2 0 3 1 1 1 2 0 3 1 3 1 2 0 5
