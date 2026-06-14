#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    int res=1;
    int mn = v[0].second;
    for(int i=1;i<n;i++){
	if(v[i].second < mn ){
	    res++;
	    mn=v[i].second;
	}
    }
    cout<<res;


    return 0;
}
