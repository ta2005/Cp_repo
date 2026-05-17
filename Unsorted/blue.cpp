#include <bits/stdc++.h> 

using namespace std; 

//a distinct part if 
//all of its adjancent are with
//but the corers are blu;
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<short>> v(n,vector<short> (n));
    for (int i=0;i<n;i++){
	for (int j=0;j<m;j++){
	    cin>>v[i][j];
	}
    }
}
