#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i].first>>v[i].second;
    }
    //since the res does not depend on the length of the task
    //finishing taks that end later is more beinficial
    sort(v.begin(),v.end());
    long long curr{};
    long long res{};
    for(int i=0;i<n;i++){
	curr+=v[i].first;	
	res+=(v[i].second-curr);
    }
    cout<<res;
    return 0;
}

// 3 6 10 8 15 5 12
