#include <bits/stdc++.h>
using namespace std;

struct op {
    int l, r, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<op> v(m);
    vector<int> total_op(m);
    vector<int> add(n);
    vector<int> pref(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i].l >> v[i].r >> v[i].d;
    }
    for(int i=0;i<m;i++){
	int x,y;
	cin>>x>>y;
	x--;
	y--;
	total_op[x]++;
	total_op[y]--;
    }
    for(int i=0;i<m;i++){
	add[v[i].l-1]+=total_op[i]*v[i].d;
	add[v[i].r-1]-=total_op[i]*v[i].d;
    }
    for(int i=1;i<=n;i++){
	pref[i]=pref[i-1]+add[i-1];
    }
    for(int i=0;i<n;i++){
	cout<<a[i]+pref[i+1];
    }

    return 0;
}
