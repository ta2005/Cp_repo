#include <bits/stdc++.h>
#include <utility>

using namespace std;

int main() {
    ifstream in("socdist.in");
    int n, m;
    in >> n >> m;
    vector<pair<long long, long long>> v(m);
    for (int i = 0; i < m; i++) {
        in >> v[i].first >> v[i].second;
    }
    auto check = [&](long long x) {
	//this is the nbr of cows that could be served
	long long nbr{1};
	long long prev=v[0].first;
	for(int i=0;i<m;i++){
	    long long start=max(prev+x,v[i].first);
	    if((v[i].second-start)>=0){
		long long len=v[i].second-start;
		nbr+=(len/x+1);
		prev=(v[i].second-len%x);
	    }
	}
        return nbr>=n;
    };
    sort(v.begin(), v.end());
    long long l = 0;
    long long r = LONG_LONG_MAX-5;
    while (l < r) {
        long long mid = l + ((r - l)+1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    ofstream out("socdist.out");
    out<<l;
}
// 5 3 0 2 4 7 9 9
