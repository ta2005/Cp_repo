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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int>mem;
	vector<bool>res(n);
	int acc=n;
	for(int i=0;i<n;i++){
	    switch(s[i]-'0'){
		case 3:
		    res[i]=true;acc--;break;
		case 1:
		    mem.push_back(i);break;
		case 2:
		    if(mem.empty()){
			res[i]=true;
		    }else{
			int pos=mem.back();
			mem.pop_back();
			res[pos]=true;
		    };acc--;break;
	    };
	}
	cout<<acc<<endl;
	for(int i=0;i<n;i++){
	    if(res[i])continue;
	    cout<<i+1<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 6 2 12 2 13 2 23 6 112332 3 112 6 211213
