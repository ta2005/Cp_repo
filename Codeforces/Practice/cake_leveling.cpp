#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
	int n;cin>>n;
	vector<int>v(n);
	vector<long long>res(n);
	res[0]=v[0];
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	long long acc{};
	int m{};
	for(int i=1;i<n;i++){
	    acc+=v[i];
	    m=min(v[i],m);
	    res[i]=max(m,
	}
    }

    return 0;
}
