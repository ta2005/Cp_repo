#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<long long>pref(n+1);
    for(int i=0;i<n;i++){
	cin>>v[i];
	pref[i+1]=pref[i]+v[i];
    }
    int res{};
    if(n==1){
	cout<<0;
	return 0;
    }
    for(int i=1;i<(n);i++){
	int pre=pref[i];
	int post=pref[n]-pref[i];
	// println("pre {} : post {}",pre,post);
	if(pre == post){
	    res++;
	}
    }
    cout<<res;

}
