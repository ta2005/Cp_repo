#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/304/problem/C
//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2==0){
	cout<<-1;
	return 0;
    }
    vector<int>a(n);
    vector<int>b(n);
    vector<int>c(n);
    for(int i=0;i<n;i++){
	a[i]=i;
	b[i]=i;
	c[i]=(2*i)%n;
    }
    for_each(a.begin(),a.end(),[](auto i){cout<<i<<' ';});
    cout<<endl;
    for_each(b.begin(),b.end(),[](auto i){cout<<i<<' ';});
    cout<<endl;
    for_each(c.begin(),c.end(),[](auto i){cout<<i<<' ';});
    return 0;
}
