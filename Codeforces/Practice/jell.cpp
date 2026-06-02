#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,m,k;
	cin>>n>>m>>k;
	vector<long long>a(n);
	vector<long long>b(m);
	long long sum{};
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    sum+=a[i];
	}
	for(int i=0;i<m;i++){
	    cin>>b[i];
	}
	//this is game will be played with 4 pieces
	//i will want to trade his biggest ele with my smallest one 
	//so does he
	if(k%2==0){
	    //if i steal 
	    cout<<sum-(max(0LL,*max_element(a.begin(),a.end())-*min_element(b.begin(),b.end())))<<'\n';
	}else{
	    //i will steal his biggest ele
	    cout<<sum+(max(0LL,*max_element(b.begin(),b.end())-*min_element(a.begin(),a.end())))<<'\n';
	}
    }
    return 0;
}

// 4 2 2 1 1 2 3 4 1 1 10000 1 2 4 5 11037 1 1 4 5 1 9 1 9 8 1 1 1 2 1
// 1 5 2 28811906 528527611 528527611 967814754 528527611 528527611 32898719 32898719
