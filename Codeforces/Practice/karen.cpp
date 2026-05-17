#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>v(2*1e5+6);
    vector<int>pref(2*1e5+6);
    vector<int>pref2(2*1e5+6);
    for(int i=0;i<n;i++){
	int l,r;
	cin>>l>>r;
	v[l]++;	
	v[r+1]--;	
    }
    for(int i=0;i<=2*1e5+4;i++){
	pref[i+1]+=pref[i]+v[i];
    }
    for(int i=0;i<=2*1e5+4;i++){
	pref2[i+1]+=pref2[i]+(pref[i]>=k);
    }
	//    for(int i=90;i<=100;i++){
	// printf("%d %d\n",i,pref[i]);
	//    }
    for(int i=0;i<q;i++){
	int a,b;
	cin>>a>>b;
	a+=2;
	b+=2;
	cout<<pref2[b]-pref2[a-1]<<'\n';
    }

    return 0;
}

// 3 2 4 91 94 92 97 97 99 92 94 93 97 95 96 90 100
