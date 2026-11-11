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

constexpr int N = 3 * 1e5;
vector<int> primes;
bool is_prime[N];
// use bitset<N> is_prime; to have O(N/64) memory complexity
// using bitset you can solve upto around N = 10^8 in 1s
void sieve_v0() {
    for (int i = 2; i < N; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    sieve_v0();
        set<int> s(primes.begin(), primes.end());
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
	vector<int>res(n);
        for (int i = 0; i < n; i++) {
	    cin>>res[i];
        }
	for(int i=0;i<n;i++){
	    if(s.count(res[i])==0){
		res[i]=*s.upper_bound(res[i]);
	    }
	}
	for(auto i:res){
	    cout<<i<<' ';
	}
	cout<<endl;
    }
    return 0;
}

// 3 2 7 12 3 7 9 12 7 8 76 49 26 24 80 99
