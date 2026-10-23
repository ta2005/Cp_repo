#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int k;
    long long n;
    cin>>n>>k;
    vector<long long>v(k);
    long long count{};
    for(int i=0;i<k;i++){
	cin>>v[i];
	count+=(n/v[i]);
    }
    for(int i=1;i<(1<<k);i++){
	if(__builtin_popcount(i)==1)continue;
	long long acc=1;
	bool test=true;
	for(int j=0;j<20;j++){
	    if(i&(1<<j)){
		if(acc>=(n/v[j])){
		    test=false;
		    break;
		}
		acc*=v[j];
	    }
	}
	if(test)count+=(__builtin_popcount(i)%2==0?-1:1)*(n/acc);
    }
    cout<<count;


    return 0;
}
