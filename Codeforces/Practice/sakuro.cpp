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
const double EPS=numeric_limits<double>::epsilon();
using clk = chrono::high_resolution_clock;
// }}}

int gcd(int a,int b,int& x,int& y){
    if(b==0){
	x=1;
	y=0;
	return a;
    }
    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
	int n;
	cin>>n;
	vector<int>v(n);
	constexpr int mod=1e9+7;
	vector<int>pref(n+1);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    pref[i+1]=pref[i]+v[i];
	    pref[i+1]%=mod;
	}
	int acc{};
	for(int i=0;i<n;i++){
	    acc+=(v[i]+mod)*((pref[n]-pref[i+1]+mod)%mod);
	    acc%=mod;
	}
	int nbr=(n)*(n-1)/2;
	nbr%=mod;
	int x,y;
	assert(gcd(nbr,mod,x,y)==1);
	x=(x%mod+mod)%mod;
	cout<<(acc*x)%mod<<endl;
    }
    return 0;
}
// 1 20 274817018 727927537 177146587 950730875 848678841 986943245 866831634 471268221 70951207 618585678 530410183 762303308 895314401 861394835 171550414 321095104 570723799 766272005 317771790 967177177
