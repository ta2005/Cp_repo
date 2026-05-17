#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
	int n;
	cin >> n;
	int l = 0;
	int r = n;
	int res = -1;
	while (l <= r) {
	    int m = (l + r) / 2;
	    if (m * m == n) {
		res = m;
	    }
	    if ((m * m) < n) {
		l = m + 1;
	    } else {
		r = m - 1;
	    }
	}
	if (res != -1) {
	    cout << 0 << ' ' << res  << endl;

	} else {
	    cout << -1 << endl;
	}
    }
}
