#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,l;
    cin>>n>>l;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    sort(v.begin(),v.end());
    double m=max(v[0],l-v[n-1]);
    for(int i=0;i<n-1;i++){
	m=max(m,(double)(v[i+1]-v[i])/2);
    }
    printf("%.09G",m);

    return 0;
}
