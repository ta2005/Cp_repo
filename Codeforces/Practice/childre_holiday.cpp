#include <bits/stdc++.h>
using namespace std;

struct ass {
    int t, z, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<ass> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].t >> v[i].z >> v[i].y;
    }
    auto check = [&](int x) {
        // check wheter i can do all the ballons in t time
        long long res{};
        for (int i = 0; i < n; i++) {
            int cycle = v[i].t * v[i].z + v[i].y;
            int nbr = x / cycle;
            int rest = x % cycle;
            res += nbr * v[i].z;
	    res += min(v[i].z,rest/v[i].t);
            // t z y
            // the lenght of a cycle
            // is t*z + y
            // and we get z balloon out of if
        }
        return res >= m;
    };
    int l = 0, r = INT_MAX;
    while (l < r) {
        long long int mid = (long long)(l + (r - l) / 2);
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
    {
        long long int x = l;
	long long int remaining = m;
        for (int i = 0; i < n; i++) {
            long long acc{};
            int cycle = v[i].t * v[i].z + v[i].y;
            int nbr = x / cycle;
            int rest = x % cycle;
            acc += nbr * v[i].z;
	    acc += min(v[i].z,rest/v[i].t);
	    long long take=min(acc,remaining);
            cout << take << ' ';
	    remaining-=take;
            // t z y
            // the lenght of a cycle
            // is t*z + y
            // and we get z balloon out of if
        }
    }
    return 0;
}

// 1 2 2 1 1 1 1 2
//
