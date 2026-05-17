#include <bits/stdc++.h>
using namespace std;

//check if the distance v[r]>=x+v[l]-1
bool check(vector<int>&v,int c,int x){
    int curr=v[0];
    for (int i=0;i<c-1;i++){
	auto it=lower_bound(v.begin(),v.end(),curr+x);
	if (it==v.end()) return false;
	curr=*it;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,c;
	cin>>n>>c;
	vector<int>v(n);
	for (int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	int l = 0, r = v[n-1]-v[0];
	// cout<<"hello";
	while (l < r) {
	    int mid = l + (r - l+1) / 2;
	    //i could do it with mid
	    if (check(v,c,mid)) {
		l = mid;
	    } else {
		r = mid-1;
	    }
	} 

	cout<<r<<'\n';

    }
    return 0;
}

// 5 3 1 2 8 4 9
