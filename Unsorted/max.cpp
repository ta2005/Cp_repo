#include <bits/stdc++.h>
using namespace std;

void calc(vector<int>&pow,int x){
    for(int i=0;i<31;i++){
	if((x&(1<<i))!=0){
	    pow[i]++;
	}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	vector<int>pow(31);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    calc(pow,v[i]);
	}
	for(int i=30;i>=0;i--){
	    if(k==0) break;
	    if(k>=(n-pow[i])){
		k-=n-pow[i];
		pow[i]=n;
	    }
	}
	int res{};
	for(int i=0;i<31;i++){
	    if(pow[i]==n){
		res|=1<<i;
	    }
	}
	cout<<res<<'\n';
    }

    return 0;
}
// 4 3 2 2 1 1 7 0 4 6 6 28 6 6 12 1 30 0 4 4 3 1 3 1
