#include <bits/stdc++.h>
using namespace std;

struct all {
    int x, y, t;
};
bool check(all i,vector<all>::iterator it){
    long long  time = abs(i.t - (*it).t);
    long long dx = i.x - (*it).x;
    long long dy = i.y - (*it).y;
    long long dis = dx * dx + dy * dy;
    return dis>time*time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int g;
    int n;
    cin >> g >> n;
    vector<all> v(g);
    for (int i = 0; i < g; i++) {
	cin >> v[i].x >> v[i].y >> v[i].t;
    }
    sort(v.begin(), v.end(),
	    [](const all &x, const all &y) { return x.t < y.t; });
    vector<all> w(n);
    long long count{};
    for (int i = 0; i < n; i++) {
	cin >> w[i].x >> w[i].y >> w[i].t;
	auto it = lower_bound(v.begin(), v.end(), w[i],
		[](const all &x, const all &y) { return x.t < y.t; });
	bool innocent=false;
	if (it != v.end()) {
	    if (check(w[i],it)) innocent=true;
	}
	if(it!=v.begin()){
	    if (check(w[i],it-1)) innocent=true;
	}
	count+=innocent;
    }
    cout << count<<'\n';

    return 0;
}
// 2 4 0 0 100 50 0 200 0 50 50 1000 1000 0 50 0 200 10 0 170
