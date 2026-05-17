#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for (int i=0;i<n;i++){
	cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(),v.end(),std::greater<pair<int,int>>());
    long long  count{1};
    long long  res{};
    for (int i=0;i<n;i++){
	res+=v[i].second;
	count+=v[i].first;
	count--;
	if (count==0) break;
    }
    cout<<res;
    return 0;
}

// 2 1 0 2 0
