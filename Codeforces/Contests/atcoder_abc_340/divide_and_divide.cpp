#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> floor_ciel(long long n){
    if(n%2==0){
	return {n/2,n/2};
    }else{
	return {n/2,n/2+1};
    }
}

long long divide(long long n,map<long,long>&m){
    if(n==1) return 0;
    if(m.count(n)) return m[n];
    m[n]=n+divide(floor_ciel(n).first,m)+divide(floor_ciel(n).second,m);
    return m[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    // if n is even i put n/2 and n/2 
    // if n is odd i put n/2 (the c one) and n/2+1
    // so one for n/2 or n/2+1 is even 
    map<long,long>m;
    cout<<divide(n,m);
    return 0;
}
