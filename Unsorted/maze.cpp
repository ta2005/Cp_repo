// Pavel loves grid mazes. A grid maze is an n × m rectangle maze where each cell is either empty, or is a wall. You can go from one cell to another only if both cells are empty and have a common side.
//
// Pavel drew a grid maze with all empty cells forming a connected area. That is, you can go from any empty cell to any other one. Pavel doesn't like it when his maze has too little walls. He wants to turn exactly k empty cells into walls so that all the remaining cells still formed a connected area. Help him.
// Input
//
// The first line contains three integers n, m, k (1 ≤ n, m ≤ 500, 0 ≤ k < s), where n and m are the maze's height and width, correspondingly, k is the number of walls Pavel wants to add and letter s represents the number of empty cells in the original maze.
//
// Each of the next n lines contains m characters. They describe the original maze. If a character on a line equals ".", then the corresponding cell is empty and if the character equals "#", then the cell is a wall.
// Output
//
// Print n lines containing m characters each: the new maze that fits Pavel's requirements. Mark the empty cells that you transformed into walls as "X", the other cells must be left without changes (that is, "." and "#").
//
// It is guaranteed that a solution exists. If there are multiple solutions you can output any of them.
//

#include <bits/stdc++.h>
using namespace std;


void dfs(int x,int y,int n,int m,vector<string>&v,vector<vector<bool>>&visited,int&count,int k){
    if (x>=m || x<0  || y>=n || y<0 || count==k || visited[x][y]||v[x][y]=='#') return;
    visited[x][y]=true;
    //let the programming gods forgive me for this atorcity
    array<pair<int,int>,4> neigh={{{x+1,y}, {x,y+1}, {x-1,y}, {x,y-1}}};
    for (auto i:neigh){
	dfs(i.first,i.second,n,m,v,visited,count,k);
    }
    if (count<k){
	count++;
	v[x][y]='X';
    }
}

//notes to my self 
//if this was a real app
//i would have made a class of map
//that would have hade v visited n and m
//becuase this is bad

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>m>>n>>k;
    vector<string> v(m);
    for (int i=0;i<m;i++){
	cin>>v[i];
    }
    for (int i=0;i<m;i++){
	for (int j=0;j<n;j++){
	    if (v[i][j]=='#' || v[i][j]=='X') continue;
	    vector<vector<bool>> visisted(m,vector<bool>(n));
	    vector<string> map=v;
	    //i will start dfs from an empty cell 
	    //no need for adj list as the adjacendcy of a cell are 8 fro meach side
	    //until i reach a wall near that wall from the same direction that i came from 
	    //only and only this doexn't box any other cell
	    //my job is to find if such a cell exits
	    int count{};
	    dfs(i,j,n,m,map,visisted,count,k);
	    if (count==k){
		for (auto i:map){
		    cout<<i<<'\n';
		}

		return 0;
	    }
	}
    }
    return 0;
}

// 3 4 2 #..# ..#. #...
