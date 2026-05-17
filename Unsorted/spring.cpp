#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long int m, a, b, c;
        cin  >> a >> b >> c>>m;
        long long int div_a = m / a;
        long long int div_b = m / b;
	long long int div_c = m / c;
        long long int ppcm_ab = lcm(a,b);
        long long int ppcm_cb = lcm(c,b);
        long long int ppcm_ca = lcm(c,a);
        long long int div_ab = (m / ppcm_ab);
        long long int div_cb = (m / ppcm_cb);
        long long int div_ca = (m / ppcm_ca);
	long long int ppcm_all=lcm(ppcm_ab,c);
        long long all = m/ppcm_all;
        cout << (div_a + all - div_ab - div_ca) * 6 + all * 2 +
                    3 * (div_ab + div_ca-2*all)
	     << ' '
             << (div_b + all - div_ab - div_cb) * 6 + all * 2 +
                    3 * (div_cb + div_ab-2*all)
	    << ' '
             << (div_c + all - div_cb - div_ca) * 6 + all * 2 +
                    3 * (div_ca + div_cb-2*all)
	    << "\n";
    }
    return 0;
}

// 4 2 1 3 10 1 1 8 5 6 20 15 1000 650650 1092 157437 100000000000000000
