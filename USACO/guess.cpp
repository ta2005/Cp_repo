#include <bits/stdc++.h>
using namespace std;

int ask(int r){
    int res;
    cout<<"? "<<1<<' '<<r<<endl;
    cin>>res;
    if (res==-1){
	exit(0);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,k;
    cin>>n>>t>>k;
    int l=1,r=n;
    while(l<r){
	int mid = l + (r - l) / 2;
	//this is the nbr of zeros in the range 
	int res=ask(mid);
	int nbr_zero=mid-res;
	if(nbr_zero>=k){
	    r=mid;
	}else{
	    l=mid+1;
	}
    }
    cout<<'!'<<' '<<l;
    return 0;
}
