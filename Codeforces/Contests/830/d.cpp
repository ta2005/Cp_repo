#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;cin>>n;
	vector<int>x(n);
	vector<int>y(n);
	for(int i=0;i<n;i++){
	    cin>>x[i];
	}
	for(int i=0;i<n;i++){
	    cin>>y[i];
	}
	vector<int>diff(n);
	for(int i=0;i<n;i++){
	    diff[i]=y[i]-x[i];
	}
	sort(diff.begin(),diff.end());
	// for(auto i:diff){
	//     cout<<i<<' ';
	// }
	int g_count{};
	int l=0;
	int r=n-1;
	while(l<r){
	    while(l<r && diff[l]+diff[r]<0){
		l++;
	    }
	    if(l!=r){
		g_count++;
	    }
	    l++;
	    r--;
	}
	cout<<g_count<<'\n';
    }
    return 0;
}

// 6 6 8 3 9 2 4 5 5 3 1 4 5 10 4 1 2 3 4 1 1 2 2 3 2 3 7 1 3 10 6 2 3 6 9 5 7 3 2 7 10 6 10 6 5 4 2 1 8 100 1 1 1 1 1 200 6 1 4 1 2 4 2 1 3 3 2 3 4
