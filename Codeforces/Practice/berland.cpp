// CP Template{{{
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
        map<int,vector<int>> uni;
        vector<pii> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].fi;
            v[i].fi--;
        }
        for (int i = 0; i < n; i++) {
            cin >> v[i].se;
        }
        for (auto i : v) {
            uni[i.fi].push_back(i.se);
        }
        for (auto& i:uni) {
            sort(i.se.begin(), i.se.end(), std::greater<int>());
        }
	vector<int>pref(2*1e5+1);
	vector<int>out(n+1);
	for(auto &[u,skills]:uni){
	    pref.resize(skills.size()+1);
	    for(int i=0;i<(int)(skills.size());i++){
		pref[i+1]=pref[i]+skills[i];
	    }
	    for(int k=1;k<=(int)(skills.size());k++){
		int take=(skills.size())-(skills.size())%k;
		out[k]+=pref[take];
	    }
	    pref.clear();
	}
	for(int k=1;k<=n;k++){
	    cout<<out[k]<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 4 7 1 2 1 2 1 2 1 6 8 3 1 5 1 5 10 1 1 1 2 2 2 2 3 3 3 3435 3014 2241 2233 2893 2102 2286 2175 1961 2567 6 3 3 3 3 3 3 5 9 6 7 9 7 1 1 3083 4 7 1 2 1 2 1 2 1 6 8 3 1 5 1 5 10 1 1 1 2 2 2 2 3 3 3 3435 3014 2241 2233 2893 2102 2286 2175 1961 2567 6 3 3 3 3 3 3 5 9 6 7 9 7 1 1 3083
//1 7 1 2 1 2 1 2 1 6 8 3 1 5 1 5
