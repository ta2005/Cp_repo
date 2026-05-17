#include <bits/stdc++.h>
using namespace std;

struct direction{
    int x;
    int y;
    char d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
	cin >> v[i];
    }
    pair<int, int> u{-1, -1};
    for (int i = 0; i < n && u.first == -1; i++) {
	for (int j = 0; j < m && u.first == -1; j++) {
	    if (v[i][j] == 'A') {
		u = {i, j};
	    }
	}
    }
    queue<pair<int, int>> q;
    q.push(u);
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    visited[u.first][u.second]=true;
    vector<vector<int>> distance(n,vector<int>(m));
    vector<vector<char>> prev(n,vector<char>(m));
    while (!q.empty()) {
	auto s = q.front();
	q.pop();
	array<direction, 4> arr{{
	    {s.first, s.second + 1,'R'},
	    {s.first + 1, s.second,'D'},
	    {s.first, s.second - 1,'L'},
	    {s.first - 1, s.second,'U'},
	}};
	for (auto i : arr) {
	    if (i.x >= n || i.x < 0 || i.y >= m
			     || i.y < 0 || v[i.x][i.y] == '#'
			     || visited[i.x][i.y])
		continue;
	    visited[i.x][i.y]=true;
	    distance[i.x][i.y]=distance[s.first][s.second]+1;
	    prev[i.x][i.y]=i.d;
	    q.push({i.x,i.y});
	    
	    if (v[i.x][i.y]=='B'){
		cout<<"YES\n";
		cout<<distance[i.x][i.y]<<'\n';
		pair<int,int>cor{i.x,i.y};
		string res;
		res.reserve(distance[i.x][i.y]);
		for (int s=0;s<distance[i.x][i.y];s++){
		    res+=prev[cor.first][cor.second];
		    switch (prev[cor.first][cor.second]) {
			case 'L' :cor.second+=1;break;
			case 'R' :cor.second-=1;break;
			case 'D' :cor.first-=1;break;
			case 'U' :cor.first+=1;break;
		    }
		}
		reverse(res.begin(),res.end());
		cout<<res;
		return 0;
	    }
	}
    }
    cout<<"NO";

    return 0;
}

// 5 8 ######## #.A#...# #.##.#B# #......# ########
