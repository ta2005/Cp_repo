#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    //v[i][j]==true iif s[l..r] is pal
    int n=(int)s.size();
    vector<vector<bool>>v(n,vector<bool>(n));
    for(int i=0;i<n;i++){
	v[i][i]=true;
    }
    for(int i=0;i<n-1;i++){
	if(s[i]==s[i+1]){
	    v[i][i+1]=true;
	    v[i+1][i]=true;
	}
    }
    for(int i=0;i<n;i++){
	//checking by lenght 
	//by indecises is too hard

	for(int j=i+1;j<(n);j++){
	    if(v[i]==v[j] && v[i+1][j-1]){
		v[i][j]=true;
	    }
	}
    }
    for(int i=0;i<n;i++){
	//checking by lenght 
	//by indecises is too hard

	for(int j=0;j<(n);j++){
	    cout<<i<<' '<<j<<' '<<v[i][j]<<endl;
	}
    }
    return 0;
}

// caaaba 5 1 1 1 4 2 3 4 6 4 5
