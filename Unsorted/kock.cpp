#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int x,y;
	cin>>x>>y;
	int count{};
	if(x%2==1){
	    count++;
	}
	if(y%2==1){
	    count++;
	}
	if(count<=1){
	    cout<<"YES\n";
	}else{
	    cout<<"NO\n";
	}
    }

    return 0;
}
