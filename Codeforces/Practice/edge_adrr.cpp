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

void dfs(int u,int p,vector<vector<int>>&adj,set<int>&s){
    s.insert(u);
    if(u==0) return;
    for(auto node:adj[u]){
	if(node==p)continue;
	dfs(node,u,adj,s);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n);
	for(int i=0;i<(n-1);i++){
	    int u,v;
	    cin>>u>>v;
	    --u;--v;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	//this is the distance from all v[i] to n
	set<int>s(adj[0].begin(),adj[0].end());
	set<int>res;
	dfs(n-1,-1,adj,res);
	vector<int>dis(n);
	vector<bool>visited(n);
	queue<int>q;
	q.push(n-1);
	dis[n-1]=0;
	visited[n-1]=true;
	while(!q.empty()){
	    int u=q.front();
	    q.pop();
	    for(auto node:adj[u]){
		if(visited[node])continue;
		dis[node]=dis[u]+1;
		visited[node]=true;
		q.push(node);
	    }
	}
	int out{dis[0]};
	for(int i=0;i<m;i++){
	    // any operation int the part of the tree such that n is not a 
	    // child of does not concern us
	    // so only in the ones we are concerned about 
	    // is dis[i]<dis[1] creating a edge there 
	    // we will need to remove a vertex from the path 
	    // from i to 1 meaning we will make the path shoter
	    int a;
	    cin>>a;
	    --a;
	    if(res.count(a)==0)continue;
	    out=max(out,dis[a]+1);
	}
	cout<<out<<endl;
    }
    return 0;
}
// 5 2 2 1 2 2 2 3 2 1 2 2 3 2 3 7 2 1 2 2 3 3 7 2 4 4 5 1 6 6 5 10 4 1 2 2 3 3 10 2 4 4 5 5 6 1 7 7 8 8 9 9 8 6 10 7 1 1 2 2 7 1 3 3 4 4 5 5 6 6
// 1 7 1 1 2 2 7 1 3 3 4 4 5 5 6 6
