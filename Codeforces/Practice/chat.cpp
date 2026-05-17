#include <bits/stdc++.h>
using namespace std;

long long int emotes(long long int k,long long int i){
    if(i<=k){
	return (long long)(i)*(i+1)/2LL;
    }else{
	long long res = (long long)(k-1)*(k)/2LL;
	return res+(i-k+1)*(3*k-i)/2;
    }
    // return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int k;
	long long x;
	cin>>k>>x;
	//i will bs for the last layer i can reach
	long long int l = 1, r = 2*k-1;
	while (l < r) {
	    long long int mid = l+ (r-l)/ 2;
	    if (emotes(k,mid)>=x) {
		r = mid;
	    } else {
		l = mid+1;
	    }
	} 
	cout<<l<<'\n';
	// for(int i=1;i<=2*k-1;i++){
	//     cout<<emotes(k,i)<<endl;
	// }
    }
    return 0;
}

// 7 4 6 4 7 1 2 3 7 2 5 100 1 1000000000 923456789987654321
