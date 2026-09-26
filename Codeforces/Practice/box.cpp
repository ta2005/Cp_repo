#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> res(n);
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        res[0] = v[0];
        s.erase(v[0]);
        int poss = true;
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i - 1]) {
                res[i] = v[i];
                s.erase(v[i]);
            } else {
            }
        }
        // what does this mean ??
        // this means that the elemenet
        // that we have is less then the one asked for
        // we simply check if we have such an element
        // this should be done in a seperate loop;
        for (int i = 1; i < n; i++) {
            if (v[i - 1] == v[i]) {
                if (*s.begin() > v[i]) {
                    poss = false;
                    break;
                } else {
                    res[i] = *s.begin();
                    s.erase(*s.begin());
                }
            }
        }
        if (!poss) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                cout << res[i] << ' ';
            }
	    cout<<'\n';
        }
    }
}

    // 4 5 1 3 4 5 5 4 1 1 3 4 2 2 2 1 1
