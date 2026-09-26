#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> m;
        int o = {};
        int e2 = {};
        int e4 = {};
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            switch (a % 4) {
                case 2:
                    e2++;
                    break;
                case 0:
                    e4++;
                    break;
                case 1:
                case 3:
                    o++;
                    break;
            }
        }
        int res=max({o,e2,e4});
        cout << res << '\n';
    }
}

// 5 2 1 3 4 1 1 1 2 3 6 7 8 4 2 2 2 2 5 1 10 100 1000 100000
