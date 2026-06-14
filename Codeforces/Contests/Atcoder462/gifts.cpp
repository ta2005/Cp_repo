#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<set<int>>res(n);
    for(int i=0;i<n;i++){
	int k;cin>>k;
	for(int j=0;j<k;j++){
	    int person;cin>>person;
	    --person;
	    res[person].insert(i+1);
	}
    }
    for(auto& s:res){
	cout<<s.size()<<' ';
	for(auto i:s){
	    cout<<i<<' ';
	}
	cout<<'\n';
    }

    return 0;
}

// 7 1 3 4 3 4 6 7 1 7 3 2 6 7 2 3 7 1 4 1 5
