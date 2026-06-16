#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
	long long n,m;
	cin>>n>>m;
	long long count_2{};
	long long a=n;
	while(a%2==0){
	    count_2++;
	    a/=2;
	}
	long long count_5{};
	while(a%5==0){
	    count_5++;
	    a/=5;
	}
	long long nbr_zero=min(count_2,count_5);
	count_2-=nbr_zero;
	count_5-=nbr_zero;
	long long acc{1};
	while(acc*2<=m && count_2<count_5){
	    count_2++;
	    acc*=2; 
	}
	while(acc*5<=m && count_5<count_2){
	    count_5++;
	    acc*=5; 
	}
	while(acc*10<=m){
	    acc*=10; 
	}
	//now for the max 
	long long mul=acc;
	for(;(mul+acc)<=m;mul+=acc){
	}
	cout<<n*mul<<'\n';
	//n*m is less than 1e18 so the max nbr of zeros
	//is 18
	//we can iterate from 1 to 18 and find the max possible zeros 
	//meaning if we want to have 5 zeros for we must make our nbr div 
	//by 1e5 
	//well it all depends on the nbr of 2 and 5 in the nbr 
    }
    return 0;
}

// 10 6 11 5 43 13 5 4 16 10050 12345 2 6 4 30 25 10 2 81 1 7
