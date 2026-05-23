#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n,m;
    cin>>n>>m;
    //a seq does not whose exor does not equal zero if and only if
    //there exits an interger such that the sum of that bit is odd
    //i will be having n numbers so each integer in the number 
    //has a value form 1 to m
    long long res{
	//n the pos of the odd number to choose 
	//m/2 is the possibitties
	n*m
    };
    constexpr long long mod = 1e9+9;
    if(m<62 && (1<<m)<=n){
	cout<<0;
	return 0;
    }
    for(int i=1;i<(n-1);i++){
	res*=m;
	res%=(mod);
    }
    cout<<res;

    return 0;
}
