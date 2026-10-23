#include <bits/stdc++.h>
using namespace std;

pair<int,int> extended_gcd(int a,int  b){
    int s= 0;    
    int old_s= 1;
    int r = b;    
    int old_r = a;
         
    while (r != 0){
        int quotient= old_r / r;
	int tmp=r;
	r=old_r-quotient*r;
	old_r=r;
	tmp=s;
	s=old_s-quotient*s;
	old_s=s;
    }
    int bezout_t ;
    if (b!=0){
        bezout_t=(old_r - old_s * a) / b;
    }
    else{
        bezout_t= 0;
    }
    
    return {old_s, bezout_t};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    auto res=extended_gcd(a,b);
    return 0;
}

