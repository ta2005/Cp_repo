#include <bits/stdc++.h>
using namespace std;


bool check(vector<int>&v,int c,int x){
    int n=(int)v.size();
    int count{1};
    int i=0;
    while(i<n){
	auto k = lower_bound(v.begin()+i,v.end(),v[i]+x);
	if(k!=v.end()){
	    count++;
	    i=k-v.begin();
	}else{
	    break;
	}
    }
    // printf("c=%d count=%d x=%d\n",c,count,x);
    return count>=c;
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
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	int l=0;
	int r=v[n-1]-v[0];
	while (l < r) {
	    int mid = l + (r - l+1) / 2;
	    if (check(v,c,mid)) {
		l=mid;
	    } else {
		r=mid-1;
	    }
	} 
	cout<<l<<'\n';
    }
    return 0;
}
// 1 5 3 1 2 8 4 9
