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
	vector<int>v(n);
	long long res{};
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    res+=v[i];
	    res%=3;
	}
	if(res==0){
	    cout<<0<<'\n';
	}else if(res==2){
	    cout<<1<<'\n';
	}else{
	    bool test=false;
	    for(int i=0;i<n;i++){
		if(v[i]%3==1){
		    test=true;
		    break;
		}
	    }
	    if(test){
		cout<<1<<'\n';
	    }else{
		cout<<2<<'\n';
	    }
	}
    }

    return 0;
}
