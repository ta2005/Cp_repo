#include <bits/stdc++.h>
using namespace std;

// there is no need for the visited vector
// passed si the number of cats passed to reach the node
int dfs(int i, vector<vector<int>> &v, vector<int> &cats, int passed, int m,int parent){
    if (passed > m) return 0;
    if (v[i].size() == 1) {
	return 1;
    }
    int res{};
    for (auto j : v[i]) {
	if (j==parent) continue;
	int nbr = cats[j]==0?0:passed + cats[j];
	res+=dfs(j, v, cats, nbr, m,i);
    }
    return res;
}

// since this is not a binary tree all i can do is represent is as a grpah
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<int> has_cats(n);
    for (int i = 0; i < n; i++) {
	cin >> has_cats[i];
    }
    v[0].push_back(-1);
    for (int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	v[--a].push_back(--b);
	v[b].push_back(a);
    }
    int res{};
    res=dfs(0,v,has_cats,has_cats[0],m,-1);
    cout<<res;

    return 0;
}
// 4 1 1 1 0 0 1 2 1 3 1 4

// 4 1 1 1 0 0 1 2 1 3 1 4
// 7 1 1 0 1 1 0 0 0 1 2 1 3 2 4 2 5 3 6 3 7
//3 2 1 1 1 1 2 2 3
