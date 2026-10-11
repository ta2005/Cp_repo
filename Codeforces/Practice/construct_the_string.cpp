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
	int n,a,b;
	cin>>n;
	cin>>a>>b;
	vector<char>res(n);
	vector<int>freq(b);
	for(int i=0;i<a;i++){
	    res[i]=(i%b+'a');
	    freq[i%b]++;
	}
	for(int i=a;i<n;i++){
	    freq[res[i-a]-'a']--;
	    auto it=ranges::min_element(freq);
	    int idx=it-freq.begin();
	    res[i]='a'+idx;
	    freq[idx]++;
	}
	for(auto c:res){
	    cout<<c;
	}
	cout<<endl;
	// for(int i=0;i<a;i++){
	//     cout<<res[i];
	// }
    }
    return 0;
}
