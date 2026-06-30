#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    set<char>s;
    vector<char>p(n);
    for(int i=0;i<n;i++){
	cin>>p[i];
	s.insert(p[i]);
    }
    int l=0,r=0;
    vector<int>c(256);
    long count{};
    int res{INT_MAX};
    while(r<n){
	c[p[r]]++;
	if(c[p[r]]==1) count++;
	if(count==(int)s.size()){
	    res=min(res,r-l+1);
	    while(c[p[l]]>1){
		c[p[l]]--;
		l++;
	    }
	    res=min(res,r-l+1);
	}
	r++;
    }
    cout<<res;
}
// 6 aaBCCe
