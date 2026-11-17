// CP Template{{{
#include <algorithm>
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
	int res{};
	int r=n-1;
	int l=0;
	vector<bool>used(n);
	while(!used[r]){
	    vector<int>pref;
	    pref.pb(0);
	    int nbr_0=0;
	    while(r<n && s[r]=='0'){
		nbr_0++;
		pref.pb(pref.back()+r+1);
		r--;
	    }
	    int nbr_1=0;
	    while(r<n && s[r]=='1'){
		nbr_1++;
		pref.pb(pref.back()+r+1);
		r++;
	    }
	    if(nbr_0>=nbr_1){
		res+=pref[nbr_0];
	    }else{
		int diff=nbr_1-nbr_0;
		// i will use all the 0s
		res+=pref[nbr_0];
		// from the ones i have left I will need to use min value poss
		//
	    }
	}
	cout<<res<<endl;
    }
    return 0;
}

// 4 1 1 6 101101 7 1110001 5 11111
