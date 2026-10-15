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
	int n,x;
	cin>>n>>x;
	vector<pii>a(n);
	vector<int>b(n);
	for(int i=0;i<n;i++){
	    cin>>a[i].fi;
	    a[i].se=i;
	}
	for(int i=0;i<n;i++){
	    cin>>b[i];
	}
	ranges::sort(a);
	ranges::sort(b);
	vector<int>res(n);
	for(int i=n-x;i<n;i++){
	    res[i]=b[i-(n-x)];
	}
	for(int i=0;i<n-x;i++){
	    res[i]=b[i+x];
	}
	int acc{};
	for(int i=0;i<n;i++){
	    acc+=res[i]<(a[i].fi);
	}
	if(acc!=x){
	    cout<<"NO\n";
	    continue;
	}
	cout<<"YES\n";
	vector<int>out(n);
	for(int i=0;i<n;i++){
	    out[a[i].se]=res[i];
	}
	for(auto i:out){
	    cout<<i<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 7 1 0 1 2 1 1 1 2 3 0 2 4 3 4 1 2 3 1 2 4 3 4 1 2 3 2 2 4 3 4 1 2 3 3 2 4 3 4 1 2 5 2 6 4 5 6 2 9 7 9 1 1
// 1 3 2 2 4 3 4 1 2
