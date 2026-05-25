#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x,y;
    cin>>x>>y;
    long long n;
    cin>>n;
    long long res{};
    switch((n-1)%6){
	case 0 : res=x;break;
	case 1 : res=y;break;
	case 2 : res=y-x;break;
	case 3 : res=-x;break;
	case 4 : res=-y;break;
	case 5 : res=x-y;break;
    }
    const long long mod=1e9+7;
    cout<<((res%mod)+mod)%mod;
    return 0;
}
