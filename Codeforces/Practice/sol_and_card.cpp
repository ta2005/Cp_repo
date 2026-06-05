#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    deque<int> a;
    deque<int> b;
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int el;
        cin >> el;
        a.push_back(el);
    }
    int k2;
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int el;
        cin >> el;
        b.push_back(el);
    }
    set<deque<int>> sa;
    set<deque<int>> sb;
    int count{};
    while (sa.count(a) == 0 || sb.count(b) == 0) {
        if (a.empty()) {
            cout << count << ' ' << 2;
            return 0;
        }
        if (b.empty()) {
            cout << count << ' ' << 1;
            return 0;
        }

        sa.insert(a);
        sb.insert(b);
        if (a.front() > b.front()) {
            a.push_back(b.front());
            a.push_back(a.front());
            a.pop_front();
            b.pop_front();
        } else {
            b.push_back(a.front());
            b.push_back(b.front());
            a.pop_front();
            b.pop_front();
        }
        count++;
    }
    cout << -1;

    return 0;
}
// 4 2 1 3 2 4 2
// 5 4 5 3 2 4 1 1
