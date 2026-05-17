#include <bits/stdc++.h>
using namespace std;

long long combination(int n,int k){
    if(n<k || k==0)return 1LL;
    long long res=1;
    for(long long int i=1;i<=n;i++){
	res*=i;	
    }
    for(long long int i=1;i<=k;i++){
	res/=(i)*(max(n-k,1));
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    //the output is nC4*m*2(n+m-5)
    cout<<combination(n,4)*m*(combination(n+m-5,t-5));

    return 0;
}
