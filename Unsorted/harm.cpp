#include <bits/stdc++.h>
using namespace std;

int calc(int x){
    int res{};
    int a=x;
    for(int i=2;i*i<=a;i++){
	if(x%i==0){
	    res++;
	    while(x%i==0){
		x/=i;
	    }
	}
    }
    if(x!=1) res++;
    return 1<<(res-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int l,r;
	cin>>l>>r;
	int m=l;
	for(int i=l+1;i<=r;i++){
	    // cout<<m<<' '<<calc(m)<<endl;
	    if(calc(i)>calc(m)){
		m=i;
	    }
	}
	cout<<m<<' '<<calc(m)<<'\n';
    }
    return 0;
}

// 3 5 20 50 500 2004 2025
