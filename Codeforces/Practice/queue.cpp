#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> q;
    int p1 = 0;
    {
        set<int> s;
        set<int> e;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            s.insert(a);
            e.insert(b);
            q[a] = b;
        }
        for (auto i : s) {
            if (e.count(i) == 0) {
                p1 = i;
                break;
            }
        }
    }
    vector<int> begin;
    vector<int> end;
    {
        int s_pos = q[0];
        while (s_pos != 0) {
            begin.push_back(s_pos);
            s_pos = q[s_pos];
        }
    }
    {
        int b_pos = p1;
        while (b_pos != 0) {
            end.push_back(b_pos);
            b_pos = q[b_pos];
        }
    }
    vector<int> res(n);
    for (int i = 0; i < (int)begin.size(); i++) {
        res[2 * i + 1] = begin[i];
    }
    for (int i = 0; i < (int)end.size(); i++) {
        res[2 * i] = end[i];
    }
    for (auto i : res) {
        cout << i << ' ';
    }
    return 0;
}

// 4 92 31 0 7 31 0 7 141
