#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    vector<int> suff(n + 1, 0);
    for (int i = 1; i <= n; i++) {
	suff[i]=suff[i-1];
	if (s[i-1]=='1'){
	    suff[i]+=a[i-1];
	}
    }

    int res = suff[n];

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            int calc = pref[i] + (suff[n] - suff[i + 1]);
            res = max(res, calc);
        }
    }
    
    cout << res << "\n";

    return 0;
}

// 2 3 8 10
