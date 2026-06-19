#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t,p;
    cin>>t>>p;
    int n=(int)t.length();
    vector<int>v(t.length());
    for(int i=0;i<(int)t.length();i++){
	cin>>v[i];
    }
    int l=0;
    int r=n-1;
    auto check = [&](int x){
	//each removal must be perserver the 
	//order in a
	string a=t;
	for(int i=0;i<x;i++){
	    a.erase(v[i]-1,1);
	}
	cout<<a<<'\n';
	return true;
    };
    while(l<r){
	int mid=(l+r)/2;
	if(check(mid)){
	    l=mid;
	}else{
	    r=mid-1;
	}
    }
    cout<<l;

    return 0;
}

// ababcba abb 5 3 4 1 7 6 2
