#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<long long>pref(n+1);
	for(int i=0;i<n;i++){
	    int a;
	    cin>>a;
	    pref[i+1]=pref[i]+a;
	}
	int q;
	cin>>q;
	while(q--){
	    int l,u;
	    cin>>l>>u;
	    //the most he will run
	    auto i=lower_bound(pref.begin()+l+1,pref.end(),u);
	    if(i==pref.end()){
	    }else{
	    }
	}
    }

    return 0;
}
