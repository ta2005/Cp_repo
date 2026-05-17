#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	for(int i=0;i<m;i++){
	    cin>>b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),std::greater<int>());
	long long res{};
	int i{};
	for(i=0;i<n/2;i++){
	    res+=abs(a[i]-b[i]);
	    res+=abs(a[n-i-1]-b[m-i-1]);
	}
	if(n%2==1){
	    res+=max(abs(a[i]-b[i]),abs(a[n-i-1]-b[m-i-1]));
	}
	// cout<<r<<'\n';
	cout<<res<<'\n';
    }


    return 0;
}

// 9 4 6 6 1 2 4 3 5 1 7 2 3 3 4 1 1 1 1 1 1 1 5 5 1 2 3 4 5 1 2 3 4 5 2 6 5 8 8 7 5 8 2 10 2 2 4 1 9 6 4 6 8 10 6 4 3 10 6 1 8 9 3 5 6 5 2 1 7 9 7 2 5 5 9 10 6 3 7 5 9 2 3 9 1 6 3 2 7 10 1 1 5
// 1 1 6 3 2 7 10 1 1 5
