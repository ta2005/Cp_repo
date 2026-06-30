#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,q;
    cin>>n>>q;
    vector<int> pref(n+1);
    for (int i=0;i<n;i++){
	int a;
	cin>>a;
	pref[i+1]=pref[i]+a;
    }
    for (int i=0;i<q;i++){
	int l,r;
	cin>>l>>r;
	cout<<pref[r]-pref[l-1]<<'\n';
    }
}
