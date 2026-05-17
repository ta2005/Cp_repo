#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int>v(1001);
    for(int i=0;i<n;i++){
	int a;
	cin>>a;
	v[a]++;
    }
    sort(v.begin(),v.end(),std::greater<int>());
    
    return 0;
}
