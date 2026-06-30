#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<vector<int>> v(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
		cin>>v[i][j];
	    }
	}
	vector<int>res(2*n+1);
	set<int>s;
	for(int i=1;i<=2*n;i++){
	    s.insert(i);
	}
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++){
		res[i+j]=v[i][j];
		s.erase(v[i][j]);
	    }
	}
	int a=*s.begin();
	cout<<a<<' ';
	for(int i=2;i<=2*n;i++){
	    cout<<res[i]<<' ';
	}
	cout<<'\n';
    }

    return 0;
}
