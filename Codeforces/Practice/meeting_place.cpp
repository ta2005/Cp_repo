#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

pair<double, double> intersect(pair<double, double> r1,
                               pair<double, double> r2) {
    if (r1.second < r2.first || r2.second < r1.first) {
        return {-1.0, -1.0};
    }
    return {max(r1.first, r2.first), min(r1.second, r2.second)};
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    auto check = [&](double x) {
        // check whether they can reach the same pos
        // after x second
        pair<double, double> range = {
            max(v[0].first - v[0].second * x, 0.0),
            v[0].first + v[0].second * x,
        };
        for (int i = 1; i < n; i++) {
            pair<double, double> curr = {
                max(v[i].first - v[i].second * x, 0.0),
                v[i].first + v[i].second * x,
            };
	    range=intersect(range,curr);
	    if(range.first==-1.0){
		return false;
	    }
        }
	return true;
    };
    double l = 0;
    double r = 1e9;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
	if(check(mid)){
	    r=mid;
	}else{
	    l=mid;
	}
    }
    cout<<setprecision(9)<<r;
}

// 3 7 1 3 1 2 1
