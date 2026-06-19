#include <bits/stdc++.h>
using namespace std;

int main() {
    constexpr long long max=2e7;
    vector<bool>is_prime(max,true);
    vector<int>primes;
    is_prime[1]=false;
    is_prime[0]=false;
    for(long long i=2;i<max;i++){
	if(is_prime[i]){
	    primes.push_back(i);
	    for(long long j=i*i;j<max;j+=i){
		is_prime[j]=false;
	    }
	}
    }
    vector<pair<int, int>> twin_prime;
    for (int i=0;i<(int)primes.size()-1;i++) {
	if(primes[i] == primes[i+1]-2){
	    twin_prime.push_back({primes[i],primes[i+1]});
	}
    }
    int n;
    // the biggest n is 1000000
    // 18409199 according the net
    // a sieve should work
    while (scanf("%d",&n)!=EOF) {
	printf("(%d, %d)\n",twin_prime[n-1].first,twin_prime[n-1].second);
    }
    return 0;
}
