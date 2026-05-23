#include <bits/stdc++.h>
using namespace std;
//
//https://codeforces.com/problemset/problem/2211/A
//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	for (int i=0; i<n; i++) {
	    int a;
	    cin>>a;
	}
	for(int i=0;i<n;i++){
	    if(n>=2){
		cout<<2<<' ';
	    }else{
		cout<<1<<' ';
	    }
	}
	cout<<'\n';
    }

    return 0;
}
