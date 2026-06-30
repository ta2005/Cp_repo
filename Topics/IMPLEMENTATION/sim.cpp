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
	pair<int,int>state{0,0};
	for (int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	if ((v[0+1]-v[0])!=1){
	    state.first+=v[0]%2;
	    state.second+=(1-v[0]%2);
	}
	if ((v[n-1]-v[n-1-1])!=1){
	    state.first+=v[n-1]%2;
	    state.second+=(1-v[n-1]%2);
	}
	for (int i=1;i<(n-1);i++){
	    if ((v[i]-v[i-1])!=1 && (v[i+1]-v[i])!=1){
		state.first+=v[i]%2;
		state.second+=(1-v[i]%2);
	    }
	}
	if (state.first%2!=0 || state.second%2!=0){
	    cout<<"NO\n";
	}else{
	    cout<<"YES\n";
	}
    }

    return 0;
}

// 7 4 11 14 16 12 2 1 8 4 1 1 1 1 4 1 2 5 6 2 12 13 6 1 6 3 10 5 8 6 1 12 3 10 5 8
