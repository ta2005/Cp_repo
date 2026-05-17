#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++){
	cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l=0;
    int r=n-1; 
    long long count{};
    while (l<r){
	int sum=v[r];
	while (l<r && (sum+v[l])<=4){
	    sum+=v[l];
	    l++;
	}
	count++;
	r--;
    }
    count+=l==r;
    cout<<count;
    return 0;
}

// 5 1 2 4 3 3
// 8 2 3 4 4 2 1 3 1
// 12 1   1  1  1  1  1  1  1  1  1  1  1  
