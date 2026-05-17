#include <algorithm>
#include <bits/stdc++.h> 

using namespace std; 

struct tower{
    int pos;
    int nbr;
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0;i<n;i++){
	cin>>a[i];
    }
    for (int i=0;i<m;i++){
	cin>>b[i];
    }
    int res{};
    for (int i=0;i<n;i++){
	auto it = lower_bound(b.begin(),b.end(),a[i]);
	res=max(res,abs(*it-a[i]));
    }
    cout<<res;
}

// 3 2 -2 2 4 -3 0
