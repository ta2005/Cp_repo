#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++){
	cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l=v[0];
    int r=v.back();
    while(r-l>n){
    }
    return 0;
}
