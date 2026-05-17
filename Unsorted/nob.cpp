#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> v(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[--a].insert(--b);
        v[b].insert(a);
    }
    int q;
    cin >> q;
    // one thing is for certain
    // for nobel of index 1:
    // he has no friend -> nobles of index 2 either has no friends or all his
    // friends have power bigger than him he have friends : he will be the frist
    // to be killed then nobel tow either has no friend or he will be killed and
    // so on to figure if an elder is dead or not i iterate through the array if
    // they have a friend who has power bigger then them they will die if they
    // are alnoe they will stay alive in the operations: I have two kinds to
    // update my state table add a friendship: this only makes lonely not
    // lonely:they will dies if that index is bigger than their power remove a
    // friendship i will maybe put the adj list as a set but only if it tle
    set<int> state;
    for (int i = 0; i < n; i++) {
        if (!v[i].empty() && *v[i].rbegin() > i) {
	    state.insert(i);
        }
    }
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            int a, b;
            cin >> a >> b;
            v[--a].insert(--b);
            v[b].insert(a);
            if (!v[a].empty() && *v[a].rbegin() > a) {
		state.insert(a);
            }
            if (!v[b].empty() && *v[b].rbegin() > b) {
		state.insert(b);
            }
        }; break;
        case 2: {
            int a, b;
            cin >> a >> b;
            v[--a].erase(--b);
            v[b].erase(a);
            if (v[a].empty() || *v[a].rbegin() < a) {
		state.erase(a);
            }
            if (v[b].empty() || *v[b].rbegin() < b) {
		state.erase(b);
            }
        } break;
        case 3: {
	    cout<<n-(int)state.size()<<'\n';
        }
        }
    }
    return 0;
}

// 4 3 2 1 1 3 3 4 4 3 1 2 3 2 3 1 3
