#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
	cin >> v[i];
    }
    // all i need to do i minize the difference between the curr max and min
    int i{};
    vector<pair<int, int>> res{};
    for (i = 0; i < k; i++) {
	auto mn = min_element(v.begin(), v.end());
	auto mx = max_element(v.begin(), v.end());
	if (*mn == *mx || (*mx-*mn)==1)
	    break;
	res.push_back({mx - v.begin(), mn - v.begin()});
	*mn = *mn + 1;
	*mx = *mx - 1;
    }
    auto mn = min_element(v.begin(), v.end());
    auto mx = max_element(v.begin(), v.end());
    cout << *mx-*mn << ' ' << res.size()<<'\n';
    for_each(res.begin(), res.end(),
	    [](auto x) { cout << x.first+1 << ' ' << x.second+1 << '\n'; });

    return 0;
}

// 3 2 5 8 5
