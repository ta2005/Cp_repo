#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;
        
        int L = x;
        int R = x;
        
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            
            if (l <= R && r >= L) {
                L = min(L, l);
                R = max(R, r);
            }
        }
        
        cout << R - L + 1 << '\n';
    }
    return 0;
}
