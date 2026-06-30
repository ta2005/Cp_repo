#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    vector<string>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    bool test = true;
    for (int j = 0; j < n; j++) {
        if (v[j][0] == 'x') {
            test = false;
        }
    }
    int res{};
    bool prev_free = test;
    int count{prev_free};
    for (int i = 1; i < d; i++) {
        bool test = true;
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 'x') {
                test = false;
            }
        }
        if (test) {
            count++;
        } else {
            res = max(res, count);
            count = 0;
        }
        prev_free = test;
    }
    res = max(res, count);
    cout << res;
    return 0;
}
