#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &v, int a, int b) {
    for (auto i : v[a]) {
        if (i == b)
            return true;
    }
    return false;
}

bool connected(vector<vector<int>> &v, int s) {
    vector<int> w;
    for (int i = 0; i < 5; i++) {
        if (s & (1 << i)) {
            w.push_back(i);
        }
    }
    // check it there is a connection
    return check(v, w[0], w[1]) && check(v, w[0], w[2]) && check(v, w[1], w[2]);
}

bool unconnected(vector<vector<int>> &v, int s) { 
    vector<int> w;
    for (int i = 0; i < 5; i++) {
        if (s & (1 << i)) {
            w.push_back(i);
        }
    }
    return !check(v, w[0], w[1]) && !check(v, w[0], w[2]) && !check(v, w[1], w[2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> v(5);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
    }
    bool test=false;
    for (int s = 0; s < (1 << 5); s++) {
        if (__builtin_popcount(s) != 3)
            continue;
        if(connected(v, s)){
	    test=true;
	    break;
	}
        if(unconnected(v, s)){
	    test=true;
	    break;
	}
    }
    if (test){
	cout<<"WIN\n";
    }else{
	cout<<"FAIL\n";
    }

    return 0;
}

// 4 1 3 2 3 1 4 5 3
