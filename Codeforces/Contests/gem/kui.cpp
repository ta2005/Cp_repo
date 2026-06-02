#include <bits/stdc++.h>
using namespace std;

//first try btw

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long int>v(n);
    vector<long long int>pref1(n+1);
    vector<long long int>pref2(n+1);
    for(int i=0;i<n;i++){
	cin>>v[i];
	pref1[i+1]=pref1[i]+v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
	pref2[i+1]=pref2[i]+v[i];
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
	int t,l,r;
	cin>>t>>l>>r;
	switch (t){
	    case 1: cout<<pref1[r]-pref1[l-1]<<'\n';break;
	    case 2: cout<<pref2[r]-pref2[l-1]<<'\n';break;
	}
    }

    return 0;
}

// 6 6 4 2 7 2 7 3 2 3 6 1 3 4 1 1 6
