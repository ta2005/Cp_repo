#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,q;
    cin>>n>>q;
    vector<vector<int>> prefix(n+1,vector<int> (n+1));
    for (int i=0;i<n;i++){
	for (int j=0;j<n;j++){
	    char a;
	    cin>>a;
	    prefix[i+1][j+1]=prefix[i+1][j]+prefix[i][j+1]+(a=='*')-prefix[i][j];
	}
    }
    for (int i=0;i<q;i++){
	int y1,x1,y2,x2;
	cin>>y1>>x1>>y2>>x2;	
	int res=prefix[y2][x2]-prefix[y2][x1-1]-prefix[y1-1][x2]
	    +prefix[y1-1][x1-1];
	cout<<res<<'\n';
    }
} 
// 4 3 .*.. *.** **.. **** 2 2 3 4 3 1 3 1 1 1 2 2
