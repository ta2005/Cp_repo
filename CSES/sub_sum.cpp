#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<long long>pref(n+1);
    long long res{};
    map<long long ,long long >m;
    m[0]++;
    for (int i=0;i<n;i++){
	int a;
	cin>>a;
	pref[i+1]=pref[i]+a;
	m[pref[i+1]]++;
	if (m.count(pref[i+1]-x)){
	    res+=m.count(pref[i+1]-x);
	}
    }
    cout<<res;
    return 0;
}
// 5 7 2 4 1 2 7
