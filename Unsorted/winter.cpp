#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>v(n);
	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    v[--a].push_back(--b);
	    v[b].push_back(a);
	}
	//m=x*(y+1)
	int y{};
	for(int i=0;i<n;i++){
	    if(v[i].size()==1){
		y=v[v[i][0]].size()-1;
		break;
	    }
	}
	int x=(m)/(y+1);
	cout<<x<<' '<<y<<'\n';
    }

    return 0;
}
// 3 21 20 21 20 5 20 13 20 1 3 11 3 10 3 4 8 19 8 14 8 9 7 12 7 17 7 18 6 16 6 2 6 6 15 7 15 8 15 20 15 3 15 7 6 1 2 1 3 2 4 2 5 3 6 3 7 9 8 9 3 3 6 6 2 2 1 5 2 2 7 4 3 3 8
