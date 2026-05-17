#include <bits/stdc++.h>
#include <climits>

using namespace std;


struct dir {
    char d;
    int s;
};

int main() {
    ifstream in("mowing.in");
    int n;
    in >> n;
    vector<dir> state(n);
    for (int i = 0; i < n; i++) {
	in >> state[i].d >> state[i].s;
    }
    int res=INT_MAX;
    int time = 1;
    vector<vector<int>> f(3000, vector<int>(3000));
    int x{1500};
    int y{1500};
    for (int k = 0; k < n; k++) {
	int x1{x};
	int y1{y};
	switch (state[k].d) {
	    case 'N':
		y += state[k].s;
		break;
	    case 'S':
		y -= state[k].s;
		break;
	    case 'E':
		x += state[k].s;
		break;
	    case 'W':
		x -= state[k].s;
		break;
	}
	if (x1<x){
	    for (int a = x1+1; a <=x; a++) {
		if (f[a][y] != 0) {
		    res = min(res, time-f[a][y]);
		}
		f[a][y] = time++;
	    }
	}
	else{
	    for (int a = x1-1; a >=x; a--) {
		if (f[a][y] != 0) {
		    res = min(res, time-f[a][y]);
		}
		f[a][y] = time++;
	    }
	}
	if (y1<y){
	    for (int a = y1+1; a <=y; a++) {
		if (f[x][a] != 0) {
		    res = min(res, time-f[x][a]);
		}
		f[x][a] = time++;
	    }
	}
	else{
	    for (int a = y1-1; a >=y; a--) {
		if (f[x][a] != 0) {
		    res = min(res, time-f[x][a]);
		}
		f[x][a] = time++;
	    }
	}
    }
    ofstream out("mowing.out");
    if (res==INT_MAX){
	out << -1;
    }else{
	out<<res;
    }
}
// 6 N 10 E 2 S 3 W 4 S 5 E 8
