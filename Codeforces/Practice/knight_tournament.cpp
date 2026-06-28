#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    set<int>s;
    vector<int>res(n+1);
    for(int i=1;i<=n;i++){
	s.insert(i);	
    }
    for(int i=0;i<m;i++){
	int l,r,x;
	cin>>l>>r>>x;
	auto it=s.lower_bound(l);
	// to prevent pointer invalidation
	vector<int>tmp;
	while(it != s.end() && *it<r+1){
	    if(*it!=x){
		res[*it]=x;
		tmp.push_back(*it);
	    }
	    it++;
	}
	for(auto del:tmp){
	    s.erase(del);
	}
    }
    for(int i=1;i<=n;i++){
	cout<<res[i]<<' ';
    }
    return 0;
}

// 4 3 1 2 1 1 3 3 1 4 4
