#include <bits/stdc++.h>
using namespace std;


//you can have empty subarrays
bool check(vector<int>&v,int n,int k,long long int x){
    int count{};
    int i{};
    long long int sum{};
    while(i<n && count<k){
	if ((sum+v[i])<=x){
	    sum+=v[i];
	}else{
	    if (v[i]>x) return false;
	    sum=v[i];
	    count++;
	}
	i++;
    }
    if (i==n) return count<k;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    long long sum{};
    for(int i=0;i<n;i++){
	cin>>v[i];
	sum+=v[i];
    }
    long long int l = sum/k, r = sum;
    while (l < r) {
	long long int mid = l + (r - l) / 2;
	// printf("l=%d r=%d mind=%d check=%d\n",l,r,mid, check(v,n,k,mid));
	if (check(v,n,k,mid)) {
	    r = mid;
	} else {
	    l = mid+1;
	}
	// cout<<mid<<endl;
    } 
    cout<<l;
    return 0;
}
// 5 3 2 4 7 3 5
