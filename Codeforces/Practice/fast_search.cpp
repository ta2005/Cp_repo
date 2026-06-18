#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    sort(v.begin(),v.end());
    int q;cin>>q;
    for(int i=0;i<q;i++){
	int l,r;
	cin>>l>>r;
	vector<int>::iterator it1=lower_bound(v.begin(),v.end(),l);
	vector<int>::iterator it2=upper_bound(v.begin(),v.end(),r);
	cout<<(it2-it1)<<' ';
    }
    return 0;
}
