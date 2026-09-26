#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>v(3);
	int res{};
	for(int i=0;i<3;i++){
	    cin>>v[i];
	    res=max(res,n-v[i]);
	}
	cout<<res<<'\n';
    }
}


// 6 3 3 3 3 4 4 4 3 1 1 1 1 9 9 8 9 5 0 5 5 6 4 3 2
