#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            m[v[i]]++;
        }
        int m_a = 0, m_b = 0, m_c = 0;
        int result{};
        while (m.count(result) != 0 && m.at(result) == 3) {
            result++;
        }
        m_c = result;
        result = 0;
        while (m.count(result) != 0 && m.at(result) == 2) {
            result++;
        }
        m_b = result;
        m_a = result;
	printf("%d %d %d\n",m_a,m_b,m_c);
        if ((m_c + m_b) >= m_a) {
            cout << "YES\n";
            vector<char> res(n, 'C');
            set<int> c;
            for (int i = 0; i < n; i++) {
                if (v[i] < m_a && c.count(v[i]) == 0) {
                    res[i] = 'A';
                    c.insert(v[i]);
                }
            }
            set<int> cb;
            for (int i = 0; i < n; i++) {
                if (v[i] < m_b && c.count(v[i]) == 0) {
                    res[i] = 'B';
                    cb.insert(v[i]);
                }
            }
            for (auto i : res) {
                cout << i;
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}

// 5 6 1 0 0 1 2 1 4 0 0 0 0 3 0 2 2 4 6 7 6 7 5 0 0 0 1 2
