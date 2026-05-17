#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,x;
    cin>>n>>x;
    vector<long long>pref(n+1);
    map<long long ,int>m;
    m[0]++;
    long long int res{};
    for (int i=1;i<=n;i++){
	int a;
	cin>>a;
	pref[i]=pref[i-1]+a;
	if(m.count(-x+pref[i])){
	    res+=m[pref[i]-x];
	}
	m[pref[i]]++;
    }
    cout<<res;
}

//5 7 2 -1 3 5 -2
