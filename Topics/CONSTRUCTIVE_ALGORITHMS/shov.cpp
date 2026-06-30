#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	//need to find the biggest number i such that n%i==0 
	//and i<=k;
	long long res{n};
	for(long long int i=1;i*i<=n;i++){
	    if(n%i==0){
		if(i<=k){
		    res=min(res,n/i);
		}
		if(n/i<=k){
		    res=min(res,i);
		}
	    }
	}
	printf("%lld\n",res);
    }
    return 0;
}

// 5 8 7 8 1 6 10 999999733 999999732 999999733 999999733
