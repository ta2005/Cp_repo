#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    map<int,int>m;
    int l=0,r=0;
    int res=0;
    while(r<n){
	m[v[r]]++;
	while(m.size()>2){
	    m[v[l]]--;
	    if(m[v[l]]==0){
		m.erase(v[l]);
	    }
	    l++;
	}
	res=max(res,r-l+1);
	r++;
    }
    cout<<res;
    return 0;
}
