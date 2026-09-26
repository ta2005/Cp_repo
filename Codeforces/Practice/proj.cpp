#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
	long long  x,y,z;
	cin>>x>>y>>z;
	long long res=0;
	long long d = y-x;
	int i=0;
	for (;(x+i)<=d && i<z;i++){
	    res+=(d%(x+i));
	}
	if((x+i)>=d){
	    res+=d*(z-i);
	}
	cout<<res<<'\n';
    }
}

// 7 1 1 1 3 10 2 3 8 6 7 20 1 10 25 100 8 36 17 1 999900 1000000000000
