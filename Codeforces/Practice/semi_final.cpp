#include <bits/stdc++.h>
using namespace std;

// observartions : the player whose positon
// are less than n/2 can always pass
//if v[i] can't make it then v[i+1] can't either 

struct p {
    int t;
    int s;
    int pos;

    bool operator < (const p& a){
	    return this->t < a.t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>s1(n);
    vector<int>s2(n);
    vector<p>all(2*n);
    for(int i=0;i<n;i++){
	cin>>s1[i]>>s2[i];
	all[2*i]={s1[i],1,i};
	all[2*i+1]={s2[i],2,i};
    }
    sort(all.begin(),all.end());
    vector<int>res1(n);
    vector<int>res2(n);
    for(int i=0;i<(n/2);i++){
	res1[i]=1;
	res2[i]=1;
    }
    for(int i=0;i<n;i++){
	switch (all[i].s){
	    case 1: res1[all[i].pos]=1;break;
	    case 2: res2[all[i].pos]=1;break;
	}
    }
    for(auto i : res1 ){
	cout<<i;
    }
    cout<<'\n';
    for(auto i : res2 ){
	cout<<i;
    }
    // for(int i=0

    return 0;
}
