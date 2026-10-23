#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    long long sum{};
    for (int i=0;i<n;i++){
	cin>>v[i];
	sum+=v[i];
    }
    sort(v.begin(),v.end());
    long long res{LONG_LONG_MAX};
    int curr{};
    for(int i=0;i<n;i++){
	long long calc=(i*v[i]-curr)+(sum-v[i]-curr-v[i]*(n-i-1));
	// cout<<calc<<endl;
	res=min(res,calc);
	curr+=v[i];
    }
    cout<<res;
    return 0;
}
// 5 2 3 1 5 2
