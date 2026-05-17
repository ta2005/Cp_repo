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
	vector<int>v(n);
	for (int i=0;i<n;i++){
	    cin>>v[i];
	}
	bool test=true;
	int m=v[0];
	for (int i=0;i<(n);i++){
	    if (v[i]>=(m*2)){
		test=false;
		break;
	    }
	    m=min(v[i],m);
	}
	if (test){
	    cout<<"YES\n";
	}else{
	    cout<<"NO\n";
	}
    }

    return 0;
}

// 4 4 5 6 1 1 3 3 1 2 3 40 60 90 2 1 1
