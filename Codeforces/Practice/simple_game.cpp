#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int dis(int a,int b){
    return abs(a-b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    assert(n>=m);
    if(n==1){
	cout<<1;
	return 0;
    }
    if (dis(m,1)<dis(m,n)){
	cout<<min(m+1,n);
    }else{
	//this one is probabl uneeded
	cout<<max(m-1,0);
    }

    return 0;
}
