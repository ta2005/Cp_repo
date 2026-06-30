#include <bits/stdc++.h> 
#include<stdlib.h>

long long cmp(const void * a,const void *b){
    return *(long long *)a-*(long long *)b;
}

using namespace std; 

int main() {
    long long t;
    cin>>t;
    while (t--){
	long long n,m;
	cin>>n>>m;
	vector<vector<long long>> arr(m,vector<long long> (n));
	for (long long i=0;i<n;i++){
	    for(long long j=0;j<m;j++){
		cin>>arr[j][i];
	    }
	}
	long long res{};
	for (long long i=0;i<m;i++){
	    sort(arr[i].begin(),arr[i].end());
	}
	for (long long i=0;i<m;i++){
	    for(long long j=0;j<n;j++){
		res+=arr[i][j]*(2*j+1-n);
	    }
	}
	cout<<res<<'\n';
    }
}

// 3 3 5 1 4 2 8 5 7 9 2 1 4 3 8 5 3 1 1 4 4 15 1 10 4 3 1 2 3 3 2 1 1 2 1 4 2 7
