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
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	// The thing about or is that it can only add bits never remove 
	// them so for example for
	// a1|a2=a2|a1
	// I think I can use the contribution trick
	// aka find the k for each bit b and the res is the max between them
	int res{-1};
	for(int i=0;i<21;i++){
	    int curr{0};
	    int count{0};
	    for(int j=0;j<n;j++){
		if((v[j]&(1<<i))==0){
		    count++;
		}else{
		    curr=max(curr,count);
		    count=0;
		}
	    }
	    curr=max(curr,count);
	    // cout<<curr<<endl;;
	    if(curr!=n){
		if(res==-1){
		    res=curr+1;
		}else{
		    res=max(res,curr+1);
		}
	    }
	}
	cout<<(res==-1?1:res)<<endl;
    }
    return 0;
}
// 1 5 3 0 1 4 2
