#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int> v(2*n);
	for (int i=0;i<(2*n);i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	int l=0,r=0;
	int sum{};
	while (r<(2*n)){
	    while (r<(2*n) && v[r]==v[l]){
		r++;
	    }
	    sum+=((l-r%2)==0)?2:1;
	    l=r;
	}
	cout<<sum<<'\n';
    }
}

// 7 2 1 2 3 4 3 5 5 5 5 5 5 4 3 3 7 6 3 7 8 7 2 2 2 2 2 6 1 2 3 4 5 4 1 4 1 5 4 6 4 1 2 1 2 1 2 1 2 5 9 9 9 7 7 7 9 7 7 7
