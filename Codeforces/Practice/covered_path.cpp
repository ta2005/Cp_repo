#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;
    long long dis = 0;
    for(int i = 1; i <= t; i++) {
	int forward_limit = v1 + (i-1)*d;
	int backward_limit = v2 + (t-i)*d;

	dis += min(forward_limit, backward_limit);
    }
    cout<<dis;
    return 0;
}
