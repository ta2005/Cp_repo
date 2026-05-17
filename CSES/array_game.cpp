#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	vector<long long>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	if(k>=3){
	    cout<<"0\n";
	}else if(k==1){
	    sort(v.begin(),v.end());
	    long long m=LONG_LONG_MAX;
	    for(int i=0;i<n-1;i++){
		m=min(m,abs(v[i]-v[i+1]));
	    }
	    cout<<m<<'\n';
	}else{
	    sort(v.begin(),v.end());
	    long long m=LONG_LONG_MAX;
	    for(int i=0;i<n-1;i++){
		//i will need to find the miniutm of v[k]-abs(v[j]-v[i])
		for(int j=i+1;j<n;j++){
		    long long cunt=abs(v[i]-v[i+1]);
		    m=min(m,abs(v[j]-cunt)); m=min(m,cunt); 
		}
	    }
	    cout<<m<<'\n';
	}
    }
    return 0;
}
// 1 6 2 42 47 50 54 62 79

// 4 5 2 3 9 7 15 1 4 3 7 4 15 12 6 2 42 47 50 54 62 79 2 1 500000000000000000 1000000000000000000
