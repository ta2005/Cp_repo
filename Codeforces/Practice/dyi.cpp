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
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	set<int>dup;
	for(int i=0;i<n-1;i++){
	    if(v[i]==v[i+1])dup.insert(v[i]);
	}
	if(dup.size()<4){
	    cout<<0<<'\n';
	}else{
	    int a=*dup.begin();
	    int b=*(++dup.begin());
	    int c=*dup.rbegin();
	    int d=*(++dup.rbegin());
	    cout<<(c-a)*(b-d)<<'\n';
	}
    }
    return 0;
}

// 3 16 -5 1 1 2 2 3 3 4 4 5 5 6 6 7 7 10 8 0 0 -1 2 2 1 1 3 8 0 0 0 0 0 5 0 5
