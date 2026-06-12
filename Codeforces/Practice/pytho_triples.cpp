#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // a = mn , b = m**2-n**2 /2 , c = m**2 + n**2 /2
    int x;cin>>x;
    if (x==1){
	cout<<-1;
	return 0;
    }
    if (x%2==1){
	long long n=1;
	long long m=x;
	long long b = (long long)(m*m-n*n)/2;
	long long c = (long long)(m*m+n*n)/2;
	cout<<b<<' '<<c;
	return 0;
    }
    x = x * 2;
    for(long long int i=2;(i*i)<=x;i++){
	if(x%i==0){
	    long long div1=i;
	    long long div2=x/i;
	    if(div1>=div2)break;
	    if((div1+div2)%2!=0) continue;
	    long long m = (div1+div2)/2;
	    long long n = div2-m;
	    long long b = (long long)(m*n);
	    long long c = (long long)(m*m+n*n)/2;
	    cout<<b<<' '<<c;
	    return 0;
	}
    }
    cout<<-1;
    return 0;
}
