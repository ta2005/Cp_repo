#include <bits/stdc++.h> 

using namespace std; 


int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>v(2*n);
    for (int i=0;i<n;i++){
	int a;
	cin>>a;
	v[2*i]={a,1};
	cin>>a;
	v[2*i+1]={a,-1};
    }
    sort(v.begin(),v.end());
    long long m{};
    long long sum{};
    for (auto i:v){
	sum+=i.second;
	m=max(sum,m);
    }
    cout<<m;
}

// 3 5 8 2 4 3 9
