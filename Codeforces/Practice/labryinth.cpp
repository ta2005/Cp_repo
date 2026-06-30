#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U','D','L','R'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> dis(n, vector<int>(m, -1));
    vector<vector<char>> step_made(n, vector<char>(m, -1));
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'A') {
                start = {i, j};
            }
	    if (v[i][j] == 'B'){
		end = {i, j};
	    }
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    dis[start.first][start.second] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dis[nr][nc] == -1 &&
                v[nr][nc] != '#') {
		dis[nr][nc]=dis[r][c]+1;
		step_made[nr][nc]=dir[i];
		q.push({nr,nc});
            }
        }
    }
    if(dis[end.first][end.second]==-1){
	cout<<"NO\n";
	return 0;
    }
    cout<<"YES\n";
    cout<<dis[end.first][end.second]<<'\n';
    vector<char>path;
    path.reserve(dis[end.first][end.second]);
    pair<int,int>step=end;
    while(step_made[step.first][step.second]!=-1){
	path.push_back( step_made[step.first][step.second]);
	switch(step_made[step.first][step.second]){
	    case 'U': step.first+=1;break;
	    case 'D': step.first-=1;break;
	    case 'L': step.second+=1;break;
	    case 'R': step.second-=1;break;
	}
    }
    reverse(path.begin(),path.end());
    for(auto i:path){
	cout<<i;
    }
    return 0;
}
// 5 8 ######## #.A#...# #.##.#B# #......# ########
