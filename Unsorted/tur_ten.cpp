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
	for (int i=0; i<n; i++) {
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	//works both cases
	if(v[1]!=v[0]){
	    cout<<"YES\n";
	}else{
	    bool test = false;
	    for(int i=1;i<n;i++){
		if((v[i]%v[0])!=0){
		    test=true;
		    break;
		}
	    }
	    if(test){
		cout<<"YES\n";
	    }else{
		cout<<"NO\n";
	    }
	}
    }

    return 0;
}
