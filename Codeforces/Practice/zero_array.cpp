#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    cin>>v[0];
    long long int sum{};
    bool test{true};
    for (int i=1;i<n;i++){
	cin>>v[i];
	if (v[i]!=v[0]){
	    test=false;    
	}
	sum+=v[i];
    }
    if ((test || (n%2==0)) && sum%2==0){
	cout<<"YES";
    }else{
	cout<<"NO";
    }
}

// 4 1 1 2 2
// 6 1 2 3 4 5 6
