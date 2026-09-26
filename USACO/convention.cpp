#include <bits/stdc++.h>

using namespace std;

// namespace rg = std::ranges;

int main() {
    int n, m, c;
    ifstream in("convention.in");
    in >> n >> m >> c;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        in >> v[i];
    }
    sort(v.begin(),v.end());
    auto check = [&](long long x) {
        int start = 0;
        int nbr{1};
        for (int i = 0; i < n; i++) {
            if (((v[i] - v[start]) > x) || (i-start+1)>c) {
		nbr++;
		start=i;
            }
        }
        return nbr <= m;
    };
    long long r = LONG_LONG_MAX;
    long long l = 0;
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    ofstream out("convention.out");
    out << l;
}

// 6 3 2 1 1 10 14 4 3
