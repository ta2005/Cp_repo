// CP Template{{{
#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define debug(a)                                                               \
    for (auto &i : a)                                                          \
        cout << i << " ";                                                      \
    cout << endl;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
[[maybe_unused]] constexpr double EPS = numeric_limits<double>::epsilon();
using clk = chrono::high_resolution_clock;
// }}

string diff(string x, string y) {
    int l = x.size();
    string res(l, '0');
    bool holding = false;
    for (int i = 0; i < l; i++) {
        if (x[i] > y[i]) {
            res[i] = '0' + !holding;
            holding = false;
        } else if (x[i] == y[i]) {
            if (holding) {
                res[i] = '1';
                holding = true;
            } else {
                res[i] = '0';
            }
        } else {
            if (holding) {
                res[i] = '0';
                holding = true;
            } else {
                res[i] = '1';
                holding = true;
            }
        }
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << diff("000", "111");
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            v[a].pb(b);
            v[b].pb(a);
        }
        string a, b;
        cin >> a >> b;
	vector<int>dis(n,1);
	vector<bool>vis(n);
	vector<int>p(n);
	queue<int>q;
	q.push(0);
	vis[0]=true;
	while(!q.empty()){
	    int u=q.front();
	    q.pop();
	    for(auto node:v[u]){
		if(vis[node])continue;
		dis[node]=dis[u]+1;
		vis[u]=true;
		p[node]=u;
		q.push(node);
	    }
	}
	auto it=ranges::max_element(dis);
	int pos=it-dis.begin();
	int ps{dis[pos]-1};
	string patha(dis[pos],'0');
	string pathb(dis[pos],'0');
	while(pos!=0){
	    patha[ps]=a[pos];
	    pathb[ps]=b[pos];
	    pos=p[pos];
	    ps--;
	}
	auto diff_s=diff(patha,pathb);
	// print("{} {} {} {}",patha,pathb,p,dis);
    }
    return 0;
}
// 1 5 1 2 1  3 2 4 3 5 00100 00111
