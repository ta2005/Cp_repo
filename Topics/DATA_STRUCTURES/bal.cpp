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
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	int sum{1};
	int best{1};
	for(int i=1;i<n;i++){
	    if(v[i-1]+k>=v[i]){
		sum++;
	    }else{
		sum=1;
	    }
	    best=max(best,sum);
	}
	cout<<n-best<<'\n';
    }

    return 0;
}

// 7 5 1 1 2 4 5 6 1 2 10 8 3 17 3 1 20 12 5 17 12 4 2 2 4 6 8 5 3 2 3 19 10 8 3 4 1 10 5 8 1 8 3 1 4 5 10 7 3
