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
	vector<int>has(n+1,false);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end(),std::greater<int>());
	int mex{};
	for(int i=0;i<n;i++){
	    while(has[mex]){
		mex++;
	    }
	    if((v[i]-mex)>mex){
		has[mex++]=true;
	    }else if(v[i]<=n){
		has[v[i]]=true;
	    }
	}
	cout<<mex<<'\n';
    }

    return 0;
}

// 4 4 0 1 2 3 2 6 7 6 8 1 7 6 4 3 9 9 9 8 2 4 4 3 5 3
//1 9 9 9 8 2 4 4 3 5 3
