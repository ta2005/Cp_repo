#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
	int a,b;
	cin>>a>>b;
	v[--a].push_back(--b);
    }

    return 0;
}
