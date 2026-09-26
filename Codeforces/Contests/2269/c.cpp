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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        int n,k;
	cin>>n>>k;
	int res{};
	vector<int>v(n);
	vector<bool>used(n);
	for (int i = 0; i < n; i++) {
	    cin>>v[i];	
	}
	int l=k-1;
	int r=n-k;
	int nbr=n;
	int seen1{};
	int seen2{};
	while(nbr>=k){
	    if(v[l]>v[r]){
		res+=v[l];
		used[l]=true;
		if(l>r){
		    seen2++;
		}
		while(l<n && used[l]){
		    l++;
		    // this is the nbr of used we have seen
		}
		// after this loop l is not used
		// but maybe not the correct index
		while(r>=0 && used[r]){
		    r--;
		}
		int nbr_taken=(l>r)?(l-r+1)-seen2:0;
		while(nbr_taken!=0){
		    r--;
		    nbr_taken--;
		}
	    }else{
		res+=v[r];
		used[r]=true;
		if(l>r){
		    seen1++;
		}
		while(r>=0 && used[r]){
		    r--;
		    // this is the nbr of used we have seen
		}
		// after this loop l is not used
		// but maybe not the correct index
		while(l<n && used[l]){
		    l++;
		}
		int nbr_taken=(l>r)?(l-r+1)-seen1:0;
		while(nbr_taken!=0){
		    l++;
		    nbr_taken--;
		}
	    }
	    nbr--;
	}
	cout<<res<<'\n';
    }
    return 0;
}

// 4 4 2 1 2 3 4 4 4 3 4 1 2 1 1 1 6 3 1 4 8 2 6 3
