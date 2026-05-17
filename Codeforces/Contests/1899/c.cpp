
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	long long best=v[0];
	long long current_sum=v[0];
	for(int i=1;i<n;i++){
	    if(abs(v[i])%2!=abs(v[i-1])%2){
		current_sum=max((long long)v[i],v[i]+current_sum);
	    }else{
		current_sum=v[i];
	    }
	    best=max(best,current_sum);
	}
	cout<<best<<'\n';
    }
}

// 7 5 1 2 3 4 5 4 9 9 8 8 6 -1 4 -1 0 5 -4 4 -1 2 4 -3 1 -1000 3 101 -99 101 20 -10 5 -8 10 6 -10 7 9 -2 -6 7 2 -4 6 -1 7 -6 -7 4 1
//1 6 -1 4 -1 0 5 -4
//
