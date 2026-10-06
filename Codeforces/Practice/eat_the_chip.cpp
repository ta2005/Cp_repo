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
	int h,w,xa,ya,xb,yb;
	cin>>h>>w>>xa>>ya>>xb>>yb;
	if(xa>=xb){
	    cout<<"draw\n";
	    continue;
	}
	string win="alice";
	// this is the nbr of moves
	int dis=(xb-xa-1);
	if(dis%2==0){
	    // in this scenario alic will try to get as close as possbile
	    if(ya>yb){
		ya=min(w,ya+dis/2);
		yb=min(w,yb+dis/2);
	    }else{
		ya=max(1LL,ya-dis/2);
		yb=max(1LL,yb-dis/2);
	    }
	    if(abs(ya-yb)<=1){
		win="alice";
	    }else{
		win="draw";
	    }
	}else{
	    // in this scenario alic will try to get as close as possbile
	    if(ya>yb){
		ya=min(w,ya+dis/2+1);
		yb=min(w,yb+dis/2);
	    }else{
		ya=max(1LL,ya-dis/2-1);
		yb=max(1LL,yb-dis/2-1);
	    }
	    if(abs(ya-yb)<=1){
		win="bob";
	    }else{
		win="draw";
	    }
	}
	cout<<win<<'\n';
	// this is now the current work 
	// as you can see each user has at most three moves and their goal is to win
	// each game will have exactly (xb-xa) moves
	// here is the obsevation 
	// if i were to start 
	// if my vertical distance between and my op is odd 
	// the best i can do w 
	// is it is even the best i can do i win 
	// if the best i can do is draw it is in my best interest to get as far as possible from op 
	// other wise it i in my best interest to get as close to him as poss
    }
    return 0;
}
