#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    vector<long long int>pref(n+1);
    for(int i=0;i<n;i++){
	cin>>v[i];
	pref[i+1]=pref[i]+v[i];
    }
    long long res{LONG_LONG_MAX};
    int index{};
    for(int i=0;i<=n-k;i++){
	// printf("the heigth of %d starting from %d is %lld\n",k,i,pref[i+k]-pref[i]);
	if(res>pref[i+k]-pref[i]){
	    res=pref[i+k]-pref[i];
	    index=i;
	}
    }
    cout<<index+1;


    return 0;
}

// 7 3 1 2 6 1 1 7 1
