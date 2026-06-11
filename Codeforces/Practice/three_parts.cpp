#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    int r=n-1;
    int l=0;
    long long res=0;
    long long sum3=v[r];
    long long sum1=v[l];
    while(r>l){
	while(l<r && sum1<sum3){
	    sum1+=v[++l];
	}
	if(l!=r && sum1==sum3){
	    res=sum1;
	}
	sum3+=v[--r];
    }
    cout<<res<<'\n';
    return 0;
}
