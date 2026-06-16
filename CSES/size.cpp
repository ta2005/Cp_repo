#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        long long s;
        cin >> s;
        int l = 64 - __builtin_clzl(s);
        long long len = 1LL << (l-1);
        if (s != len) {
            s = 2 * len;
        }
        cout << s << endl;
    }

    return 0;
}
