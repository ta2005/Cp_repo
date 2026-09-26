#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        // let me first ignore the last one
        // we will have a seq of
        // 00000000000000xxxxxxxxxxxxxxxxxm
        // so a max of 3 distinct integers
        if (k > 3) {
            cout << 0 << '\n';
        } else if (k == 1) {
            // all zeros
            cout << 1 << '\n';
        } else if (m == 0) {
            cout << 0 << '\n';
        } else if (k == 3) {
            if (m <= n) {
                cout << 0 << '\n';
            } else {
                int a = m - n;
                int count = (m / n) - 1;
                cout << a - count << '\n';
            }
        } else {
            if (m <= n) {
                cout << m << '\n';
            } else {
                int count = (m / n) - 1;
                cout << n + count << '\n';
            }
        }
    }
}
