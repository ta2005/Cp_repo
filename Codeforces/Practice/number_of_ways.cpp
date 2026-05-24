#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    vector<long long >pref(n+1);
    for(int i=0;i<n;i++){
	cin>>v[i];
	pref[i+1]=pref[i]+v[i];
    }
    if(pref[n]%3!=0){
	cout<<0;
	return 0;
    }
    //there are negative values so i can't simply bs on the answer
    long long res{};
    vector<long long>third(n);
    //to not get fucked bu the zero i will store these in a vector
    for(int i=1;i<n;i++){
	if(pref[i]==pref[n]/3){
	    third[i]++;
	}
	if(pref[i]==2*pref[n]/3){
	    res+=third[i-1];
	}
	third[i]+=third[i-1];
    }
    cout<<res;
    return 0;
}
