#include <bits/stdc++.h>
using namespace std;

int mod;
bool cmp(const int&a,const int&b){
    return a%mod>b%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	mod=k;
	vector<int>v(n);
	long long res{};
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    res+=v[i]/k;
	    v[i]%=k;
	}
	//we only need to sort the numbers based 
	//on they rest by k
	sort(v.begin(),v.end());
	int l=0;
	int r=n-1;
	while(l<r){
	    if(v[l]+v[r]>=k){
		l++;
		r--;
		res++;
	    }else{
		l++;
	    }
	}
	cout<<res<<'\n';
    }
    return 0;
}
// 6 6 3 3 2 7 1 4 8 4 3 2 1 5 6 4 12 0 0 0 0 2 1 1 1 6 10 2 0 0 5 9 4 6 5 5 3 8 6 3 2
