#include <algorithm>
#include <bits/stdc++.h> 
#include <vector>

using namespace std; 


int main() {
    int n,m;
    cin>>n>>m;
    vector<int> c(n);
    vector<int> t(m);
    for (int i=0;i<n;i++) cin>>c[i]; 
    for (int i=0;i<m;i++) cin>>t[i]; 
    int res=INT_MAX;
    for (auto i:t){
	auto a=upper_bound(c.begin(),c.end(),i);
	auto b=lower_bound(c.begin(),c.end(),i);
	int d1,d2;
	if (a==t.end()){
	    d2=0; 
	}
	if (b==t.begin()){
	   d1=0; 
	}
    }
}
