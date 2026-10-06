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
	string s,c;
	cin>>s>>c;
	int test=false;
	int a=INT_MAX,b=INT_MAX;
	for(int i=0;i<(int)min(s.size(),c.size());i++){
	    if(s[i]<c[i]){
		// we always win in this case 
		test=true;
		a=i;b=i;
	    }else if(s[i]==c[i]){
		// we see if we can get smth better 
		for(int j=i+1;j<(int)s.size();j++){
		    if(s[j]<c[i]){
			test=true;
			b=j;
			a=i;
			break;
		    }
		}
		if(!test){
		    continue;
		}
	    }else{

		if(s[i+1]==c[i] && s[i]<c[i+1]){
		    test=true;
		    a=i;
		    b=i+1;
		}else{
		    if(s[i+1]>c[i+1]){
			break;
		    }
		    for(int j=i+2;j<(int)s.size();j++){
			if(s[j]==c[i]){
			    test=true;
			    a=i;
			    b=j;
			}
		    }
		}
		// first we need to find
		// we try to get smth better
		for(int j=i+1;j<(int)s.size();j++){
		    if(s[j]<c[i]){
			test=true;
			b=j;
			a=i;
			break;
		    }
		}
		// If we can't can we find smth equal 
		// such that c[j] < a[i]
		if(test)break;
		for(int j=i+1;j<(int)min(s.size(),c.size());j++){
		    if(s[j]==c[i] && c[j] < s[i]){
			test=true;
			b=j;
			a=i;
			break;
		    }
		}
		if(test)break;
	    }
	    break;
	}
	if(test){
	    swap(s[a],s[b]);
	    cout<<s<<endl;
	}else{
	    cout<<"---\n";
	}
    }
    return 0;
}
