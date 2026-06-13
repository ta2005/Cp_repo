#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<bool>covered(n+1);
    set<int>s;
    for(int i=2;i<=n;i++){
	if(!covered[i]){
	    for(int j=i;j<=n;j*=i){
		s.insert(j);
	    }
	    for(int d=i;d<=n;d+=i){
		covered[d]=true;
	    }
	}
    }
    cout<<s.size()<<'\n';
    for(int i:s){
	cout<<i<<' ';
    }

    return 0;
}
