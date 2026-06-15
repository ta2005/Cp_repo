#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct Query{
    string op;
    int u,v;
};

class Dsu {
  private:
    vector<int> p;
    vector<int> s;
    vector<string>res;

  public:
    Dsu(int n) {
	p.resize(n);
	iota(p.begin(),p.end(),0);
	s.assign(n,1);
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
    }
    void operator () (const Query& q){
	if (q.op=="ask"){
	    res.push_back(find(q.u)==find(q.v)?"YES\n":"NO\n");
	}else{
	    join(q.u,q.v);
	}	
    }
    void finish(){
	reverse(res.begin(),res.end());
	for(auto i:res){
	    cout<<i;
	}
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //the keyword in this problem is that the graph is empty at the end
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
	int a;
	cin>>a>>a;
    }
    vector<Query>v(k);
    for(int i=0;i<k;i++){
	string op;
	int u,w;
	cin>>op>>u>>w;
	--u;--w;
	v[i]={op,u,w};
    }
    auto d = Dsu(n);
    for(int i=k-1;i>=0;i--){
	d(v[i]);
    }
    d.finish();
    return 0;
}

// 3 3 7 1 2 2 3 3 1 ask 3 3 cut 1 2 ask 1 2 cut 1 3 ask 2 1 cut 2 3 ask 3 1
