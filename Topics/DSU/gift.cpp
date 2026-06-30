#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	v[i]=i;
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    int a;
	    cin>>a;
	    adj[--i].push_back(--a);
	}

	//this is basically reodreding 
	//let us say cow i takes gift j 
	//so need to find a cycle from cow i to cow j
	//let us say the first cow want gift 4 then there must b 
	//a path cycle of exhanges let us say
	//gift cow 3 want gift 1 cow 2 want gift 3 and cow 
	//4 want 2
    }

    return 0;
}
