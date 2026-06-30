#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	long long int n,x,y;
	cin>>n>>x>>y;
	long long lcm=(x)*(y/gcd(x,y));
	//this is the sum from n to n-n/x+1
	int nbr_pos=n/x-n/lcm;
	long long pos=(nbr_pos)*(2*n-nbr_pos+1)/2;
	int nbr_neg=n/y-n/lcm;
	long long neg=(nbr_neg)*(nbr_neg+1)/2;
	cout<<pos-neg<<'\n';
    }


    return 0;
}

// 8 7 2 3 12 6 3 9 1 9 2 2 2 100 20 50 24 4 6 1000000000 5575 25450 4 4 1
