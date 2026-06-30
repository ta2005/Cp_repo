#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int a,b,c;
	cin>>a>>b>>c;
	int time_2=abs(b-c)+abs(c);
	if(time_2<a){
	    cout<<2<<'\n';
	}else if(time_2>a){
	    cout<<1<<'\n';
	}else{
	    cout<<3<<'\n';
	}
    }

    return 0;
}
