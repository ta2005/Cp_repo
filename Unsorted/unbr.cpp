#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    //allo rows must have from 0..to n
    vector<int>v(n*n);
    vector<int>sum(n);
    vector<int>bigger;
    for(int i=0;i<n*n;i++){
	int a;
	cin>>a;
	v[i]=a;
	if(a<n){
	    sum[a]++;
	}else{
	    // bigger
	}
    }
    sort(v.begin(),v.end());
    long long res{};
    for(int i=0;i<n;i++){
    }
    return 0;
}
