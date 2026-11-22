// CP Template{{{
#include <array>
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
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    vector<vector<int>>pref(n+1,vector<int>(30));
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<30;j++){
	    pref[i+1][j]+=pref[i][j];
	    if(((v[i]>>j)&1)!=0){
		pref[i+1][j]++;
	    }
	}
    }
    for(int i=0;i<q;i++){
	int l,r,x;
	cin>>l>>r>>x;
	array<int, 30>arr;
	for(int j=0;j<30;j++){
	    arr[j]=pref[r][j]-pref[l-1][j];
	}
	int acc{};
	int rest=x;
	for(int j=0;j<30;j++){
	    if(rest==0){
		acc+=arr[j];
	    }else{
		int av=(1<<j)*arr[j];
		if(av<=rest){
		    rest-=av;
		}else{
		    acc+=(arr[j]-rest/(1<<j)-1);
		    rest=0;
		}
	    }
	}
	cout<<acc<<endl;
    }
    return 0;
}

// 4 2 10 7 3 5 1 2 5 2 4 10
