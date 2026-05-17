#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n*n);
    vector<int>des(n*n);
    for(int i=0;i<n*n;i++){
	cin>>v[i];
    }
    long long int count{};
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    des[n*i+j]=i;
	}
    }
    for(int i=0;i<n*n;i++){
	count+=abs(des[i]-v[i]);
    }
    cout<<count;
    //m[i]=n is what i want;
    //make sure no small interger has too many childer
    return 0;
}

// 3 0 0 0 5 0 1 1 2 2
//what i need to do is iterate througth the map
//for every integer that has a surplus 
//5 become 2 and so on
//if 
