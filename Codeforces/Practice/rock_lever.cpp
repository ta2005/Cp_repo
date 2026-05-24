#include <bits/stdc++.h>
using namespace std;

//two numbers  verif the property
//if they have the same biggest bit

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
	int n;cin>>n;
	vector<int>v(n);
	for (int i=0; i<n; i++) {
	    cin>>v[i];
	}
	//lsblk
	array<long long,32>res{};
	for(int i=0;i<n;i++){
	    res[32-__builtin_clz(v[i])]++;
	}
	long long count{};
	for(int i=0;i<32;i++){
	    count+=(long long)(res[i])*(res[i]-1)/2;
	}
	cout<<count<<'\n';
	// for(auto i:res){
	//     cout<<i<<' ';
	// } 
	// cout<<endl;

    }
    return 0;
}

// 5 5 1 4 3 7 10 3 1 1 1 4 6 2 5 3 2 2 4 1 1
// 
