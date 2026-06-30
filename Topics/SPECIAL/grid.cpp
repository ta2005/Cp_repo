#include <bits/stdc++.h> 

using namespace std; 

constexpr int mod=(1e9)+7;

void calc(vector<string>&v,int x,int y,int n,vector<vector<int>>&res){
    for (int i=0;i<n;i++){
	for (int j=0;j<n;j++){
	    if (v[i][j]=='*'){
		res[i][j]=0;
	    }else{
		res[i+1][j]+=res[i][j];
		res[i+1][j]%=mod;
		res[i][j+1]+=res[i][j];
		res[i][j+1]%=mod;
	    }
	}
    }
}

int main() {
    int n;
    cin>>n;
    vector<string>v(n);
    vector<vector<int>>r(n+1,(vector<int>(n+1)));
    for (int i=0;i<n;i++){
	cin>>v[i];
    }
    r[0][0]=1;
    calc(v,0,0,n,r);
	//    for (int i=0;i<n;i++){
	// for (int j=0;j<n;j++){
	//     cout<<r[i][j]<<' ';
	// }
	// cout<<endl;
	//    }
    cout<<r[n-1][n-1];
}
// 4 .... .*.. ...* *...
