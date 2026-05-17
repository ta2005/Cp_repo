#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,h;
    cin>>n>>h;
    vector<int>v(n);
    int res{};
    for(int i=0;i<n;i++){
	cin>>v[i];
	res+=(v[i]>h?2:1);
    }
    cout<<res;

    return 0;
}
