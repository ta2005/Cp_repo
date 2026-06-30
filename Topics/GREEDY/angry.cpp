#include <bits/stdc++.h> 
#include <fstream>

using namespace std; 

bool check(vector<int>&v,int r,int k){
    int i=0;
    while (k && i<v.size()){
	k--;
	i=upper_bound(v.begin()+i,v.end(),v[i]+2*r)-v.begin();
    }
    return i==v.size();
}

int main() {
    ifstream in("angry.in");
    int n,k;
    in>>n>>k;
    vector<int>v(n);
    for (int i=0;i<n;i++){
	in>>v[i];
    }
    sort(v.begin(),v.end());
    int lo=0;
    int hi=1e9;
    while (lo<hi){
	int mid=lo+(hi-lo)/2;
	if (check(v,mid,k)){
	    hi=mid;
	}else{
	    lo=mid+1;
	}
    }
    ofstream out("angry.out");
    out<<lo;
}
//we do a binary serch on R
//to find the smallest ossible value
