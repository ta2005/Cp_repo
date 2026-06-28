#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    cin>>v[i][j];
	}
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int room_count{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && v[i][j] == '.') {
                room_count++;
                queue<pair<int, int>> q;
                q.push({i, j});
		visited[i][j]=true;
                while (!q.empty()) {
                    pair<int, int> u = q.front();
                    q.pop();
                    if (u.first - 1 >= 0 && v[u.first - 1][u.second] == '.' && !visited[u.first-1][u.second]) {
                        q.push({u.first - 1, u.second});
			visited[u.first-1][u.second]=true;
                    }
                    if (u.second - 1 >= 0 && v[u.first][u.second - 1] == '.' && !visited[u.first][u.second-1]) {
                        q.push({u.first, u.second - 1});
			visited[u.first][u.second-1]=true;
                    }
                    if (u.first + 1 < n && v[u.first + 1][u.second] == '.' && !visited[u.first+1][u.second]) {
                        q.push({u.first + 1, u.second});
			visited[u.first+1][u.second]=true;
                    }
                    if (u.second + 1 < m && v[u.first][u.second + 1] == '.' && !visited[u.first][u.second+1]) {
                        q.push({u.first, u.second + 1});
			visited[u.first][u.second+1]=true;
                    }
                }
            }
        }
    }
    cout<<room_count;
    return 0;
}

// 5 8 ######## #..#...# ####.#.# #..#...# ########
//
