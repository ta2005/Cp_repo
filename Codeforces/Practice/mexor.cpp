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
	int n,k;
	cin>>n>>k;
	if(n==1){
	    if(k==1){
		yes;
		cout<<0<<endl;
	    }else{
		no;
	    }
	    continue;
	}
	if(k>=2*n){
	    no
	    continue;
	}else{
	    if(k==0){
		int xr=0;
		for(int i=0;i<n;i++){
		    xr^=(i+1);
		}
		if(xr==0){
		    yes;
		    for(int i=0;i<n;i++){
			cout<<i<<' ';
		    }
		    cout<<endl;
		}else{
		    no;
		}
		continue;
	    }
	}
	int target=k^n;
	if(target<n){
	    yes;
	    for(int i=1;i<n;i++){
		if(i==0 || i==target )continue;
		cout<<i<<' ';
	    }
	    cout<<0<<' '<<target<<endl;
	}else{
	    int a{};
	    for(int i=0;i<25;i++){
		int c=((1<<i)-1)&target;
		if(c>n)break;
		a=c;
	    }
	    int b=target-a;
	    yes;
	    for(int i=0;i<n;i++){
		if(i==0||i==a||i==b)continue;
		cout<<i<<' ';
	    }
	    cout<<0<<' '<<a<<' '<<b<<endl;
	}
	// if target is less than n
	// then we simply put 
	// res n-1 to be targer 
	// for f(n-1)==target we can use a simple startey 
	// we put target in n and 0 in n-1
	// now what if target is bigger ?
	// is it even possible?
	// let us anlyase 
	// I need to find a seq of n-2 nbrs from 1 to n-1 
	// such that they xor is eq to k xor n
	// I will need to do somthing greedy of so to fill in the nbrs
	// for example for the a1 it has two posiibe values either 1 or 0
	// if the nbr is even we take it other wise i don't also 
	// f(i) <= i (zero inxded)
	// for(int i=0;i<n;i++){
	//     cin>>res[i];
	// }
	// first obs 
	// f(0)=0
	// f(n-1)=n
	// also f monontone increasing
	// we will start building from the end and go from there 
    }
    return 0;
}

// 5 1 
// 3 1 2 0 4
// 6 1 0 1 1 3 0 4 8 5 1 9 12
