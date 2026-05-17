#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int> v(n);
	bool o=false;
	bool e=false;
	for (int i=0;i<n;i++){
	    cin>>v[i];
	    if (v[i]%2==0){
		e=true;;
	    }else{
		o=true;
	    }
	}
	if (o&&e){
	    sort(v.begin(),v.end());
	}
	for (auto i:v){
	    cout<<i<<' ';
	}
	cout<<'\n';
    }
}

// 7 4 2 3 1 4 5 3 2 1 3 4 4 3 7 5 1 2 1000000000 2 3 1 3 5 5 2 5 3 1 7 4 2 4 8 6
