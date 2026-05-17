#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,t;
    cin>>n>>t;
    vector<int>v(n);
    vector<long long>pref(n+1);
    for (int i=0;i<n;i++){
	cin>>v[i];
	pref[i+1]=pref[i]+v[i];
    }
    int l=0;
    int r=0;
    int res{};
    while (r<(n+1)){
	while((pref[r]-pref[l])>t) l++;
	res = max(res,r-l);
	r++;
    }

    cout<<res;
}

// 4 5 3 1 2 1
// 3 3 2 2 3
