#include <bits/stdc++.h> 

using namespace std; 

bool calc(long long health,long long distance,long long steps){
    
    return true;
}

int main() {
    int t;
    cin>>t; 
    while(t--){
	int h,d;
	cin>>h>>d;
	long long lo{0};
	long long hi=3e9;
	while (lo<hi){
	    long long mid = (lo+hi)/2;
	    if (calc(h,d,mid)){
		hi=mid;
	    }else{
		lo=mid+1;
	    }
	}
    }
}
