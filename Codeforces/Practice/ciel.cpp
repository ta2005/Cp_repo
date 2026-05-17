#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> j(n);
    vector<pair<int, int>> c(m);
    int nbr_attck{};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "ATK") {
            j[i].first = 0;
	    nbr_attck++;
        } else {
            j[i].first = 1;
        }
        cin >> j[i].second;
    }
    for (int i = 0; i < m; i++) {
        int attk;
        cin >> attk;
        c[i].first = 0;
        c[i].second = attk;
    }
    sort(j.begin(), j.end());
    sort(c.begin(), c.end(), greater<pair<int,int>>());
    long long damage{};
    int l{};
    int last{};
    bool test=true;
    // this is reletively easy
    // attack all attcker going from lowest to biggest
    // if the rest are defense attack as meany
    // if he has none left attack
    return 0;
}
