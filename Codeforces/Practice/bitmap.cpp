#include <bits/stdc++.h>
using namespace std;

// I could use floodfill when reaching every white cell


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));
        vector<vector<int>> min_dis(n, vector<int>(m, INT_MAX));
	queue<pair<int, int>> frontier;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                if (v[i][j] == '1') {
                    min_dis[i][j] = 0;
		    frontier.push({i,j});
                }
            }
	}
	while (!frontier.empty()) {
	    int x = frontier.front().first;
	    int y = frontier.front().second;
	    frontier.pop();


	    array<pair<int,int>,4>next={{{x+1,y},{x,y+1},{x-1,y},{x,y-1}}};
	    for(auto [nx,ny] : next){
		if (nx < 0 || nx >= (int)v.size() || ny < 0 || ny >= (int)v[0].size())
		    continue;
		if(min_dis[nx][ny]==INT_MAX){
		    frontier.push({nx, ny});
		    min_dis[nx][ny]=min_dis[x][y]+1;
		}
	    }
	}
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		cout << min_dis[i][j] << ' ';
	    }
	    cout << '\n';
	}
    }
    return 0;
}
// 1 3 4 0001 0011 0110
