#include <bits/stdc++.h>
using namespace std;


vector<long long > sieve(){
    long long n=1e6+1;
    vector<bool>is_prime(n+1,true);
    is_prime[0]=false;
    is_prime[1]=false;
    for(long long int i=2;i<=n;i++){
	if(is_prime[i] && i*i<=n){
	    for(long long j=i*i;j<=n;j+=i){
		is_prime[j]=false;
	    }
	}
    }
    vector<long long>primes;
    for(int i=0;i<=n;i++){
	if(is_prime[i]){
	    primes.push_back(i);
	}
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //a numbr is lovley if and only if there eixt a p | n 
    //such that Ap is odd
    long long int n;
    cin>>n;
    long long int res=1;
    vector<long long >primes=sieve();
    for(auto i:primes){
	if(i>n) break;
	if(n%i==0){
	    res*=i;
	}
    } 
    if(res==1 && n!=1){
	cout<<n;
    }
    cout<<res;
    return 0;
}
