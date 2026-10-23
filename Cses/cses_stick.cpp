#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    long long sum{};
    for(int i=0;i<n;i++){
	cin>>v[i];
	sum+=v[i];
    }
    sort(v.begin(),v.end());
    long long med=v[(n-1)/2];
    long long med1=v[(n)/2];
    long long res{};
    long long res1{};
    for(int i=0;i<n;i++){
	res+=(abs(v[i]-med));
	res1+=(abs(v[i]-med1));
    }
    cout<<min(res,res1);


    return 0;
}
// 5 2 3 1 5 2
