#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
	cin >> v[i];
    }
    vector<long long> pref_odd(n + 2);
    vector<long long> pref_even(n + 2);
    for (int i = 1; i <= n; i++) {
	pref_odd[i] = pref_odd[i - 1];
	pref_even[i] = pref_even[i - 1];
	if (i % 2 == 0) {
	    pref_even[i] += v[i - 1];
	} else {
	    pref_odd[i] += v[i - 1];
	}
    }
    pref_even[n+1]=pref_even[n];
    pref_odd[n+1]=pref_odd[n];
    int res{};
    for (int i = 1; i <= n; i++) {
	long long e = pref_even[i - 1] + pref_odd[n]-pref_odd[i];
	long long o = pref_odd[i - 1] + pref_even[n]-pref_even[i];
	res+=e==o;
    }
    cout<<res;

    return 0;
}

// 7 5 5 4 5 5 5 6
