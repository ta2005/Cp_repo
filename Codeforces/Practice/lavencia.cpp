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
	// this is the vector of bags
	// to get res = x
	// we need x to be the biggest value
	auto check=[&](int x){
	    vector<int>res(n);
	    res[0]=x;
	    int curr=x-1;
	    int rest=n-x;
	    for(int i=1;i<n;){
		if(curr<1)break;
		if(rest==0)break;
		int iter=min(x/curr,rest/curr);
		for(int j=0;j<iter;j++){
		    res[j+i]=curr;
		    rest-=curr;
		}
		i+=iter;
		curr--;
	    }
	    int sum{};
	    for(int i=0;i<n;i++){
		sum+=res[i];
	    }
	    return sum==n;
	};
	int l=1;
	int r=n;
	while(l<r){
	    int mid=l+(r-l)/2;
	    if(check(mid)){
		r=mid;
	    }else{
		l=mid+1;
	    }
	}
	cout<<l<<endl;
	vector<int>res(n);
	res[0]=l;
	int curr=l-1;
	int rest=n-l;
	for(int i=1;i<n;){
	    if(curr<1)break;
	    if(rest==0)break;
	    int iter=min(l/curr,rest/curr);
	    for(int j=0;j<iter;j++){
		res[j+i]=curr;
		rest-=curr;
	    }
	    i+=iter;
	    curr--;
	}
	for(int i=0;i<n;i++){
	    if(res[i]==0)break;
	    for(int j=0;j<res[i];j++){
		cout<<i+1<<' ';
	    }
	}
	cout<<endl;
	// We have to build the vector of bags
	// Well the specific bags don't matter 
	// and the sum of the values in all the bags 
	// is n
	// this is either bs or brute force

    }
    return 0;
}
// 3 1 2 1 1
// 3 4 5 8
