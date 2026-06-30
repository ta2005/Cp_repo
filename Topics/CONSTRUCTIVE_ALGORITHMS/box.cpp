#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,w;
	cin>>n>>w;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	int l=0,r=n-1;
	int sum{v[r]};
	int level{1};
	while(l<r){
	    if(sum+v[l]<=w){
		l++;
		sum+=v[l];
	    }else{
		r--;
		level++;
		sum=v[r];
	    }
	}
	cout<<level<<'\n';
    }

    return 0;
}
// 2 5 16 1 2 8 4 8 6 10 2 8 8 2 2 8
