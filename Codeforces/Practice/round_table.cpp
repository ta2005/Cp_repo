#include <bits/stdc++.h>
using namespace std;
//
//I only need to check for pirmes because if there is 
//a hexagon then there is a triange 
//for the distance  (n-p) must be divisbale by p
//meaning that p divides n so we only search the divisors of n
//also the min dis between any two point 
//must ne bigger than the biggest gap
//the first approch i will test is to see wheter 
//i can identify the biggest gap and if i can find a covering 
//with that spacing

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    for(int s=1;s<=n/3;s++){
	if(n%s==0){
	    for(int i=0;i<=s;i++){
		bool test=true;
		for(int j=i+s;;j+=s){
		    j%=n;
		    if(v[j]==0){
			test=false;
			break;
		    }
		    if(j==i)break;
		}
		if(test){
		    cout<<"YES";
		    return 0;
		}
	    }
	}
    }
    cout<<"NO";
    return 0;
}

// 6 1 0 1 1 1 0
//6 1 0 0 1 0 1
//
