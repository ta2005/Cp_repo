#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
	int n,k;
	cin>>n>>k;
	vector<pair<int,int>>v(n);
	for (int i=0;i<n;i++){
	    cin>>v[i].first;
	    v[i].second=-i-1;
	    v[i].first%=k; 
	    if (v[i].first==0) v[i].first=k;
	}
	sort(v.begin(),v.end());
	pair<int,int> s{k,0};
	for(int j=n-1;j>=0;j--){
	    cout<<-v[j].second<<' ';
	}
	cout<<'\n';
    }

    return 0;
}

// 3 3 2 1 2 3 2 3 1 1 4 3 2 8 3 5
