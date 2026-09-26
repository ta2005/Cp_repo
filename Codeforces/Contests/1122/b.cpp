#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<max(abs(a+c-b),abs(a-b))<<'\n';
    }
}

// 5 3 6 3 3 6 10 5 5 4 2 5 6 67676767 41414141 998244353
