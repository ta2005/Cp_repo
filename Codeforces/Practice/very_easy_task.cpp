#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n,x,y;
    cin>>n>>x>>y;
    int l = min(x,y), r = n*min(x,y);
    auto check = [&](long long int a){
	//I need this to make the first copy
	// if(a<min(x,y))return false;
	a-=min(x,y);
	long long acc = (a/x)+(a/y)+1;
	return (acc)>=n;
    };
    while (l < r) {
	long long int mid = l + (r - l) / 2;
	if (check(mid)) {
	    r = mid;
	} else {
	    l = mid + 1;
	}
    }
    cout<<l;

    return 0;
}
