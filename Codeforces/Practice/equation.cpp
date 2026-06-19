#include <bits/stdc++.h>
using namespace std;

constexpr double eps = 1e-8;

double calc(double x){
    return x*x+sqrt(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double c;
    cin>>c;
    double l=0;
    double r=1e15;
    for(int i=0;i<100;i++){
	double mid=(l+r)/2;
	if(calc(mid)>=c+eps){
	    r=mid;
	}else{
	    l=mid;
	}
    }
    printf("%.6f",l);

    return 0;
}
