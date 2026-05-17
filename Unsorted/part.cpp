#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<long long int>b(n);
    vector<long long int>g(m);
    for(int i=0;i<n;i++){
	cin>>b[i];
    }
    for(int i=0;i<m;i++){
	cin>>g[i];
    }
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    //i will use the bigger one since it gives me a better one than the min	
    int j=n-1;
    long long res{};
    for(int i=0;i<n;i++){
	res+=b[i]*m;
    }
    for(int i=m-1;i>=1;i--){
	res+=g[i]-b[j];
    }
    if(g[0]<b[j]){
	cout<<-1;
    }else if(g[0]==b[j]){
	cout<<res;
    }else{
	cout<<res+g[0]-b[n-2];
    }
    return 0;
}

// 3 2 1 2 1 3 4
