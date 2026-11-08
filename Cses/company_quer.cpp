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
	p.assign(size,INT_MAX);
	for(int i=0;i<(int)v.size();i++){
	    p[i+size/2]=v[i];
	}
	for(int i=size/2-1;i>0;i--){
	    p[i]=min(p[i*2],p[i*2+1]);
	}
    }
    void update(int i,int v){
	i+=p.size()/2;
	p[i]=v;
	for(i/=2;i>0;i/=2){
	    p[i]=min(p[i*2],p[i*2+1]);
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

void dfs(int u,int p,int d,vector<vector<int>>&adj,vector<int>&res,
	vector<int>&first){
    first[u]=d;
    res.pb(u);
    for(auto 

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
	int n,q;
	cin>>n>>q;
	vector<vector<int>>adj(n);
	for(int i=0;i<(n-1);i++){
	    int a;
	    cin>>a;
	    adj[i].pb(--a);
	}
	vector<int>res;
	vector<int>first(n,-1);
    }
    return 0;
}
