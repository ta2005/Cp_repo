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
    // cin >> t;
    while (t--) {
	int n,m;
	cin>>n>>m;
	vector<vector<int>>v(n,vector<int>(m));
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		cin>>v[i][j];
	    }
	}
	vector<vector<bool>>visited(n,vector<bool>(m));
	auto bfs=[&](int i,int j){
	    queue<pii> q;
	    q.push({i,j});
	    int s=0;
	    while(!q.empty()){
		auto [a,b] = q.front();
		q.pop();
		if (a < 0 || a >= n || b < 0 || b >= m || visited[a][b])
			continue;
		visited[a][b]=true;
		s++;
		if((v[a][b]&8)==0){
		    q.push({a-1,b});
		}
		if((v[a][b]&4)==0){
		    q.push({a,b+1});
		}
		if((v[a][b]&2)==0){
		    q.push({a+1,b});
		}
		if((v[a][b]&1)==0){
		    q.push({a,b-1});
		}

	    }
	    return s;
	};
	vector<int>res;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
		if(visited[i][j])continue;
		res.pb(bfs(i,j));
	    }
	}
	ranges::sort(res,greater());
	for(auto i:res){
	    cout<<i<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 4 5 9 14 11 12 13 5 15 11 6 7 5 9 14 9 14 3 2 14 3 14
