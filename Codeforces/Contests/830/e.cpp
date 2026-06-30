#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int res{};
    for(int i=0;i<25;i++){
	int x=i+2;
	cout<<"? 1 "<<x<<endl;
	long long int l1;
	cin>>l1;
	if(l1==-1){
	    cout<<"! "<<i+1<<endl;
	    return 0;
	}
	cout<<"? "<<x<<' '<<1<<endl;
	long long int l2;
	cin>>l2;
	if(l1!=l2){
	    cout<<"! "<<l1+l2<<endl;
	    return 0;
	}
	res=l1+l2;
    }
    cout<<"! "<<res<<endl;
    return 0;
}
