#include <bits/stdc++.h> 
//this is two pointers

using namespace std; 

int main() {
    int n;
    cin>>n;
    vector<int>v(2*n);
    for (int i=0;i<n;i++){
	cin>>v[i];
	v[n+i]=v[i];
    }
    set<int>s;
    int m={0};
    int l=0;
    for (int i=0;i<n;i++){
	while (s.count(v[i])!=0){
	    s.erase(v[l++]);
	}
	s.insert(v[i]);
	m=max(m,(int)s.size());
    }
    cout<<m;
}

// 8 1 2 1 3 2 7 4 2
