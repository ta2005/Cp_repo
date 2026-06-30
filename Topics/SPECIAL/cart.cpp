#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9+7;


long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1){
            res = res * a;
	    res%=mod;
	}
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	long long int n;
	cin>>n;	
	if(n>=3){
	    long long int term1 = n*(n-1)%mod;
	    term1=term1*(n-2)%mod;
	    term1=(term1*166666668);
	    long long int term2=n*(n-1)%mod;
	    long long second = (term1 + term2+4*n+8);
	    second%=mod;
	    long long first = binpow(2,n-3);
	    cout<<(first*second)%mod<<'\n';
	}else if(n==1){
	    cout<<"3\n";
	}else{
	    cout<<"9\n";
	}
    }
    return 0;
}
// >>> def calc(n):
// ...     return (2**(n-3))*(n*(n-1)*(n-2)//6 + n*(n-1)+4*n+8)
// ... print(calc(5))

// 5 4 5 6 7 8
