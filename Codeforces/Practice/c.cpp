#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> c(n);
    vector<int> t(m);
    for (int i=0;i<n;i++){
	cin>>c[i];
    }
    for (int i=0;i<m;i++){
	cin>>t[i];
    }
    int b{};
    int a{};
    int res=0;
    while (a<n){
	int dis=abs(c[a]-t[b]);
	for (int i=b+1;i<m && (abs(c[a]-t[i])<=dis);i++){
	    // cout<<i<<' '<<b<<endl;
	    dis=abs(c[a]-t[i]);
	    b=i;
	}
	res=max(res,dis);
	a++;
    }
    cout<<res;
}

// 3 2 -2 2 4 -3 0
//10 10 1 1 2 2 2 4 4 6 7 9 0 1 3 3 3 6 7 8 9 10
