#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    long long prev=v[0].second;
    for(int i=1;i<n;i++){
	if(v[i].second>=prev){
	    prev=v[i].second;
	}else{
	    prev=v[i].first;
	}
    }
    cout<<prev;
    return 0;
}
