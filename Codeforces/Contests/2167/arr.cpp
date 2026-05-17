#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = (1e9) + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
	int n;
	cin >> n;
	vector<long long> v(n);
	long long pgcd{0};
	for (int i = 0; i < n; i++) {
	    cin >> v[i];
	    pgcd = gcd(v[i], pgcd);
	}
	vector<int> primes = {2,3,  5,  7,  11, 13, 17, 19, 23,
	    29, 31, 37, 41, 43, 47, 53};
	for (int p : primes) {
	    if (pgcd % p != 0) {
		cout << p << '\n';
		break;
	    }
	}
    }
}

// 4 1 1 4 6 6 12 12 3 24 120 210 4 2 4 6 10
