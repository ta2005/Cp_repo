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
	vector<int> v(n);
	long long sum{};
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    sum+=v[i];
	}
	sort(v.begin(),v.end());
	int l=upper_bound(v.begin(),v.end(),0)-v.begin();
	long long int acc{};
	while(l<n){
	    l++; 
	    if(sum-acc<=(n-1)) break;
	    acc++;
	}
	cout<<acc<<'\n';
    }

    return 0;
}
// 3 5 0 5 1 0 1 3 3 2 1 5 1 1 1 1 1
