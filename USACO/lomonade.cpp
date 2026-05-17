#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    ifstream in("lemonade.in");
    in >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
	in >> v[i];
    }
    int count{};
    sort(v.rbegin(), v.rend());
    int join{};
    for (int i = 0; i < n; i++) {
	if (v[i] >= (join)){
	    join++;
	    count++;
	}
    }
    ofstream out("lemonade.out");
    out << count;
}
// 5 7 1 400 2 2
