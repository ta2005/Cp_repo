#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x % y == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
