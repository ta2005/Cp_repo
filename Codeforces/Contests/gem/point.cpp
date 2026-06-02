#include <bits/stdc++.h>
using namespace std;
//also first try

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    long long res{};
    for(int l=0,r=0;r<n;r++){
	while((v[r]-v[l])>d){
	    l++;
	}
	// so i track the pairs correctly
	// printf("left=%d right=%d\n",l,r);
	res+=(long long)(r-l)*(r-l-1)/2;
    }
    cout<<res<<'\n';
    return 0;
}

// 5 19 1 10 20 30 50
