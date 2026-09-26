#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int res{};	
	for(int i=0;i<(n/k);i++){
	    bool test=true;
	    for(int j=i*k;j<((i+1)*k);j++){
		if(s[j]=='0'){
		    test=false;
		}
	    }
	    res+=test;
	}
	cout<<res<<'\n';
    }
}
