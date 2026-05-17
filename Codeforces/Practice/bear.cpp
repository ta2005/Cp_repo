#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a;
    cin>>n>>a;
    --a;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    int count=v[a];
    int l=a;
    int r=n-a-1;
    if(l<r){
	for(int i=0;i<l;i++){
	    if(v[a-i-1]==v[a+1+i]){
		count+=2*v[a-i-1];
	    }
	}
	for(int i=a+l+1;i<n;i++){
	    count+=v[i];
	}
    }else{
	for(int i=0;i<r;i++){
	    if(v[a-i-1]==v[a+1+i]){
		count+=2*v[a-i-1];
	    }
	}
	for(int i=0;i<a-r;i++){
	    count+=v[i];
	}
    }
    cout<<count;
    return 0;
}

// 6 3 1 1 1 0 1 0
// 16-3-1:12
