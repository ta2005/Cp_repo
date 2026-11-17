// CP Template{{{
#include <bit>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define debug(a)                                                               \
    for (auto &i : a)                                                          \
        cout << i << " ";                                                      \
    cout << endl;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
[[maybe_unused]] constexpr double EPS = numeric_limits<double>::epsilon();
using clk = chrono::high_resolution_clock;
// }}}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
	if(n==3){
	    cout<<"2 1 3"<<endl;
	    continue;
	}
        vector<int> v(n);
        int prev{1};
	int nbr_pos=n;
        for (int i = 0; i < n; i += 2) {
            v[i] = prev++;
        }
	if(n%2==1){
	    v[n-1]=0;
	    nbr_pos-=1;
	}
	int last = bit_floor(static_cast<uint32_t>(prev));
	last *= 2;
	int l{};
	for (int i = 1; i < n; i += 2) {
	    v[i] = (v[i - 1] + last);
	    l=i;
	}
	if((nbr_pos/2)%2==1){
	    v[l]-=(last);
	    v[l]+=(last*2);
	    v[l-2]+=(last*2);
	}
        // if (n % 2 == 0) {
        //     int last = bit_floor(static_cast<uint32_t>(prev));
        //     last *= 2;
        //     for (int i = 1; i < n; i += 2) {
        //         v[i] = (v[i - 1] + last);
        //     }
        // } else {
        // }
	for(auto i:v){
	    cout<<i<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 7 8 3 4 5 6 7 9
