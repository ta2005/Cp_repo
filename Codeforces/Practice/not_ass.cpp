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


void dfs(int x,int p, vector<vector<pii>> &adj, vector<int> &res,int prev=2) {
    if(p==-1){
	int pr=prev;
	for(auto [u,i]:adj[x]){
	    if(u==p)continue;
	    res[i]=pr;
	    dfs(u,x,adj,res,res[i]);
	    pr++;
	}
    }else{
	for (auto [u,i] : adj[x]) {
	    if (p == u) continue;
	    if(prev==2){
		res[i]=3;
	    }else{
		res[i]=2;
	    }
	    dfs(u,x,adj,res,res[i]);
	}
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<pii>> adj(n);
        vector<int> res(n-1, -1);
        // for every path we must have
        // 2 and another prime
        // otherwise the some of the two p is even which
        // is not prime
        for (int i = 0; i < (n - 1); i++) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            adj[a].pb({b,i});
            adj[b].pb({a,i});
        }
	bool poss=true;
	for(auto& i:adj){
	    if(i.size()>2){
		poss=false;
		break;
	    }
	}
	if(!poss){
	    cout<<-1<<'\n';
	    continue;
	}
	dfs(0,-1,adj,res);
	for(auto i:res){
	    cout<<i<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 3 2 1 2 4 1 3 4 3 2 1 7 1 2 1 3 3 4 3 5 6 2 7 2
