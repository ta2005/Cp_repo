#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    // some observations
    // I can't simpy calc all since it's comi is n**2
    // for example 12=
    // 2*6 and 1*12 adn 3*4 so 6 combination
    // the min nbr is 1 and the max is n*n
    // will i bs on the answer
    // how can i know if there are more nbrs then me or less?
    auto check = [n](long long x) {
        long long res{};
        for (long long i = 1; i <= n; i++) {
            res += min(x / i, n);
        }
        return res >= (n * n + 1) / 2;
    };
    long long l = 0;
    long long r = 1e13;
    while(l<r){
	long long mid=l+(r-l)/2;
	if(check(mid)){
	    r=mid;
	}else{
	    l=mid+1;
	}
    }
    cout<<l;
}
