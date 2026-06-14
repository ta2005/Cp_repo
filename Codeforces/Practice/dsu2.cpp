#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Dsu {
  private:
    vector<int> p;
    vector<int> s;
    vector<pair<int,int>> m;

  public:
    Dsu(int n) {
	p.resize(n);
	iota(p.begin(),p.end(),0);
	s.assign(n,1);
	m.resize(n);
	for(int i=0;i<n;i++){
	    m[i]={i,i};
	}
    }

    int find(int x){
	assert(x>=0 && x<(int)p.size());
	if(x==p[x]) return x;
	return p[x] = find(p[x]);
    }
    void join(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a==b) return;
	if(s[a]<s[b]){
	    swap(a,b);
	}
	s[a]+=s[b];
	p[b]=a;
	m[a].first=max(m[a].first,m[b].first);
	m[a].second=min(m[a].second,m[b].second);
    }

    void set(int x){
	x=find(x);
	cout<<m[x].second+1<<' '<<m[x].first+1<<' '<<s[x]<<'\n';
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    auto d = Dsu(n);
    for(int i=0;i<m;i++){
	string op;
	cin>>op;
	if(op=="union"){
	    int a,b;
	    cin>>a>>b;
	    --a;--b;
	    d.join(a,b);
	}else{
	    int a;
	    cin>>a;
	    --a;
	    d.set(a);
	}
    }

    return 0;
}

// 5 11 union 1 2 get 3 get 2 union 2 3 get 2 union 1 3 get 5 union 4 5 get 5 union 4 1 get 5
