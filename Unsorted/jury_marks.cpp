#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k,n;
    cin>>k>>n;
    vector<int>m(k);
    vector<int>p(n);
    vector<int>pref(k+1);
    for (int i=0;i<k;i++){
	cin>>m[i];
	pref[i+1]=pref[i]+m[i];
    }
    map<int,int>mp;
    for (int i=0;i<n;i++){
	cin>>p[i];
	mp[p[i]]++;
    }
    map<int,int>res;
    for(int j=0;j<k;j++){
	//all i need is to determine only one vale 
	//and then i will have achieced the entire seq
	map<int,int>check;
	int init = p[0]-pref[j+1];
	for (int i=0;i<k;i++){
	    int jud=init+pref[i+1];
	    //since they are distncit all i need to do is check the length
	    if (mp.count(jud)!=0){
		check[jud]++;
	    }
	}
	if ((int)check.size()==n){
	    //will add to check for the uniqeness of the inti
	    res[init]++;
	}
	
    }
    cout<<res.size();
    return 0;
}

// 4 1 -5 5 0 20 10
