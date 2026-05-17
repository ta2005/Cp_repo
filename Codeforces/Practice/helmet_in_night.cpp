#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int t;
    cin>>t;
    while(t--){
	int n,p;
	cin>>n>>p;
	vector<pair<int,long long>>v(n);
	for (int i=0;i<n;i++){
	    cin>>v[i].second;
	}
	for (int i=0;i<n;i++){
	    cin>>v[i].first;
	}
	sort(v.begin(),v.end());
	long long res{p};
	long long  num{1};
	for (int i=0;i<n;i++){
	    if (num==n || v[i].first>=p) break;
	    long long add=min(n-num,v[i].second);
	    num+=add;
	    res+=add*v[i].first;
	}
	if (num!=n){
	    res+=(n-num)*p;
	}
	cout<<res<<'\n';
    }
}

// 3 6 3 2 3 2 1 1 3 4 3 2 6 3 6 1 100000 100000 1 4 94 1 4 2 3 103 96 86 57
