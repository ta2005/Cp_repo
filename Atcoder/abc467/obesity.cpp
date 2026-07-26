#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double h,w;
    cin>>h>>w;
    h/=100;
    double bmi = w/(h*h);
    if(bmi>=25.0){
	cout<<"Yes\n";
    }else{
	cout<<"No\n";
    }

    return 0;
}
