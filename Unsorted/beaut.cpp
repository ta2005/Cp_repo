#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>v(n);
	vector<int>pos(n+1);
	for (int i=0; i<n; i++) {
	    cin>>v[i];
	    pos[v[i]]=i;
	}
	vector<bool>res(n+1);
	int l=INT_MAX;
	int r=INT_MIN;
	//this is the basic idea
	//let us say i want find the the permuation 
	//for n
	//well that permutation have to have 1 2 ..n-1
	//i store the numbers position
	//and then keep two pointers to tell me 
	//the furthest indecies i am on
	//and a permuatoin is identified by it lenght
	for(int i=1;i<=n;i++){
	    int index=pos[i];
	    //l and r only change to accomadate new numbers
	    l=min(l,index);
	    r=max(r,index);
	    if(r-l+1==i){
		res[i]=1;
	    }
	}
	for(int i=1;i<n+1;i++){
	    cout<<res[i];
	}
	cout<<'\n';
    }
    return 0;
}

// 3 6 4 5 1 3 2 6 5 5 3 1 2 4 4 1 4 3 2
