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
	vector<pii>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i].first;
	    v[i].se=i;
	}
	ranges::sort(v);
	int acc{};
	int nbr{1};
	vector<int>res(n,-1);
	bool test=true;
	if(v[0].fi!=0){
	    cout<<-1<<endl;
	    continue;
	}
	// the first one will alway be zero
	int m=0;
	for(int i=1;i<n;i++){
	    if(v[i].fi==v[i-1].fi){
		nbr++;
	    }else{
		int ac=v[i].fi-acc;
		int val=ac/nbr;
		if(ac%nbr!=0 || val<=m){
		    test=false;
		    break;
		}
		// prev and m should be the same 
		m=val;
		res[v[i-1].second]=val;
		nbr=1;
		acc=v[i].fi;
	    }
	}
	if(!test || (v[n-1].fi-acc)%nbr!=0){
	    cout<<-1<<endl;
	    continue;
	}
	int val=m+1;
	for(int i=n-1;i>=0;i--){
	    if(res[v[i].se]!=-1){
		val=res[v[i].se];
	    }else{
		res[v[i].se]=val;
	    }
	}
	for(auto i:res){
	    cout<<i<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 8 1 0 5 0 4 0 4 14 3 4 0 0 3 0 0 0 3 0 1 1 4 1 1 1 1 7 0 4 4 4 4 4 9 5 0 0 0 3 3
