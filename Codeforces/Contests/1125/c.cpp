// CP Template{{{
#include <bits/stdc++.h>
#include <climits>
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
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	int res{};
	//this is a freq map
	map<int,int>m;
	int a= v[0]+v[2]-v[4];
	int b= v[1]+v[3]-v[5];
	m[v[0]+v[2]-v[4]]++;
	m[v[1]+v[3]-v[5]]++;
	res=a==b;
	for(int i=2;i+4<n;i++){
	    int acc=v[i]+v[i+2]-v[i+4];
	    // cout<<i<<' '<<acc<<' '<<endl;
	    int acc1=LONG_LONG_MAX;
	    int acc2=LONG_LONG_MAX;
	    if(i-2 >= 0){
		acc1=v[i-2]+v[i]-v[i+2];
	    }
	    if(i-4 >= 0){
		acc2=v[i-4]+v[i-2]-v[i];
	    }
	    res+=m[acc];
	    m[acc]++;
	    if(acc1!=LONG_LONG_MAX){
		if(acc1==acc){
		    res--;
		}
	    }
	    if(acc2!=LONG_LONG_MAX){
		if(acc2==acc){
		    res--;
		}
	    }
	    // cout<<"res "<<res<<'\n';
	}
	cout<<res<<endl;
    }
    return 0;
}

// 3 6 5 1 4 2 2 -4 7 0 0 0 0 0 0 0 12 -4 3 0 -4 -4 -1 -4 1 -3 -2 -2 -1
// 1 12 -4 3 0 -4 -4 -1 -4 1 -3 -2 -2 -1
