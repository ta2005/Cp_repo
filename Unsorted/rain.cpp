#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    int res{};
    for(int i=0;i<n;i++){
	int count{1};
	for(int j=i-1;j>=0;j--){
	    if(v[j]<=v[j+1]){
		count++;
	    }else{
		break;
	    }
	}
	for(int j=i+1;j<=n-1;j++){
	    if(v[j]<=v[j-1]){
		count++;
	    }else{
		break;
	    }
	}
	res=max(res,count);
    }
    cout<<res;

    return 0;
}
