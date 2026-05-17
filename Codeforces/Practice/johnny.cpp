#include <bits/stdc++.h> 

using namespace std; 

int count(long long &n,long long b){
    int c{};
    while(n%b==0){
	c++;
	n/=b;
    }
    return c;
}

int solve(long long a,long long b){
    long long int n=b/a;
    if ((b%a)!=0 || ((n&(n-1))!=0)){
	return -1;
    }else{
	int c=count(n,8);
	int d=count(n,4);
	int e=count(n,2);
	return c+d+e;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while (t--){
	long long  a,b;
	cin>>a>>b;
	if (a>b){
	    long long tmp=b;
	    b=a;
	    a=tmp;
	}
	cout<<solve(a,b)<<'\n';
    }
}
// 10 10 5 11 44 17 21 1 1 96 3 2 128 1001 1100611139403776 1000000000000000000 1000000000000000000 7 1 10 8
// 6 96 3 2 128 1001 1100611139403776 1000000000000000000 1000000000000000000 7 1 10 8
