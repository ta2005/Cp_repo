#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    //this map hold for each number wheter it has been seen or not
    map<long long ,long long >m;
    long long int res{1};
    for (int i=0;i<n;i++){
	int a;
	cin>>a;
	m[a]=m[a-1]+1;
	res=max(res,m[a]);
    }
    cout<<res; 
    return 0;
}

// 7 3 4 3 5 7 6 2
