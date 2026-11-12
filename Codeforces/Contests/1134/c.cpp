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
	// if(n==1){
	//     cout<<1<<endl;
	//     cout<<v[0]<<endl;
	//     continue;
	// }
	ranges::sort(v);
	vector<int>res(n);
	for(int i=0;i<n;i++){
	    if(i%2==0){
		res[i/2]=v[i];
	    }else{
		res[n-i/2-1]=v[i];
	    }
	}
	vector<bool>seen(n);
	seen[0]=seen[n-1]=true;
	for(int i=1;i<n;i++){
	    if(res[i]>res[i-1]){
		seen[i]=true;
	    }
	}
	for(int i=n-2;i>=0;i--){
	    if(res[i]>res[i+1]){
		seen[i]=true;
	    }
	}
	int nbr{};
	for(auto i:seen){
	    nbr+=i;
	}
	cout<<nbr<<endl;
	for(auto i:res){
	    cout<<i<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 5 6 1 2 2 3 3 3 1 5 3 7 7 7 4 4 1 3 2 11 3 1 4 1 5 9 2 6 5 3 5
