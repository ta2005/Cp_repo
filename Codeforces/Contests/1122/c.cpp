#include<bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int>pref(n+1);
	for(int i=0;i<n;i++){
	    pref[i+1]=pref[i]+s[i]-'0';
	}
	// if we put a one all the others must be one 
	if(s[0]=='1'){
	    cout<<n-pref[n]<<'\n';
	}else{
	    int res{INT_MAX};
	    for(int i=0;i<n;i++){
		if(s[i]=='1'){
		    int nbr_ones=pref[i]-pref[0];
		    // println("nbr_ones {}",nbr_ones);
		    int nbr_zeros=n-i-1-(pref[n]-pref[i+1]);
		    // println("nbr_zeros {}",nbr_zeros);
		    if(res==INT_MAX){
			res=nbr_ones+nbr_zeros;
		    }else{
			res=min(res,nbr_ones+nbr_zeros);
		    }
		}
	    }
	    cout<<min(res,pref[n])<<'\n';
	}
    }
}

// 6 4 0011 4 1000 5 01000 8 01001101 7 0101010 7 0111101
