#include <bits/stdc++.h>
using namespace std;

bool check(int n,int k,long long x){
    long long res{};
    long long curr=x;
    while(curr!=0){
	res+=curr;
	curr/=k;
    }
    return res>=n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    long long  l=0;
    long long r=1e18;
    while(l<r){
	long long int mid=l+(r-l)/2;
	if(check(n,k,mid)){
	    r=mid;
	}else{
	    l=mid+1;
	}

    }
    cout<<l;
    return 0;
}
