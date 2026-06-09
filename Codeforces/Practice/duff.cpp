#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    long long res=1;
    for(long long i=2 ; i*i <=n ;i++){
	if(n%i==0){
	    res*=i;
	    while(n%i==0){
		n/=i;
	    }
	}
    }
    if(n!=1){
	res*=n;
    }
    cout<<res;

    return 0;
}
