#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
	int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        bool has_one = false;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                has_one = true;
            }
            if (v[i] == -1 && !has_one) {
                v[i] = 1;
                has_one = true;
            }
        }
        has_one = false;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == 1) {
                has_one = true;
            }
            if (v[i] == -1 && !has_one) {
                v[i] = 1;
                has_one = true;
            } else if(v[i]==-1){
                v[i] = 0;
            }
        }
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

// 10 6 1 0 -1 0 0 1 7 0 -1 0 0 1 0 1 5 -1 0 0 -1 0 4 0 0 0 0 1 -1 6 1 0 1 0 0 -1 7 0 1 0 0 0 1 0 6 -1 -1 -1 -1 -1 -1 7 -1 0 1 -1 0 0 1 3 -1 0 0
