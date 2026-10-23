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
	int a,b,r;
	cin>>a>>b>>r;
	if(a<b){
	    swap(a,b);
	}
	int x=0;
	int curr=a-b;
	bool first=true;
	for(int i=63;i>=0;i--){
	    if((a&(1LL<<i))!=(b&(1LL<<i))){
		if((a&(1LL<<i))!=0){
		    if(first){
			first=false;
			continue;
		    }
		    if((x|(1LL<<i))>r)continue;
		    int cmp=curr-(1LL<<(i+1));
		    if(abs(cmp)<abs(curr)){
			curr=cmp;
			x|=(1LL<<i);
		    }
		}
	    }
	}
	cout<<abs(curr)<<endl;
    }
    return 0;
}

// 10 4 6 0 0 3 2 9 6 10 92 256 23 165 839 201 1 14 5 2 7 2 96549 34359 13851 853686404475946 283666553522252166 127929199446003072 735268590557942972 916721749674600979 895150420120690183
