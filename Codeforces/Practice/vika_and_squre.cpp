#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    long long  mn = *min_element(v.begin(),v.end());
    long long res=mn*n;
    for(int i=0;i<n;i++){
	v[i]-=mn;
    }
    int mx=0;
    for(int i=0;i<n;i++){
	int l=i;
	int nbr{};
	while(v[l%n]!=0){
	   l++; 
	   nbr++;
	}
	mx=max(nbr,mx);
	i=l;
    }
    cout<<mx+res;
    return 0;
}

// 5 2 4 2 3 3
