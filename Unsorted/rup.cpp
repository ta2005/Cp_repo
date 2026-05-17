#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,q;
    cin>>n>>q;
    vector<long long> v(n);
    for (int i = 0 ;i<n;i++){
	cin>>v[i];
    }
    vector<long long> p(n);
    for (int i=0;i<q;i++){
	int l,r,v;
	cin>>l>>r>>v;
	p[l]+=v;
	p[r]+=-v;
    }
    vector<long long> pref(n+1);
    for (int i = 1;i<=n;i++){
	pref[i]=pref[i-1]+p[i];
    }
    for (int i=0;i<n;i++){
	v[i]=v[i-1]+pref[i-1];
    }
    //output
}
