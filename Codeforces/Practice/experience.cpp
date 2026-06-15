#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Dsu {
  private:
    vector<int> p;
    vector<int> s;
    vector<int>score;
    vector<vector<int>>adj;

  public:
    Dsu(int n) {
	p.resize(n);
	iota(p.begin(),p.end(),0);
	s.assign(n,1);
	score.assign(n,0);
	adj.resize(n);
    }

    int find(int x){
	//I don't want to flatten the array
	assert(x>=0 && x<(int)p.size());
	while(x!=p[x]) x=p[x];
	return x;
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
	score[b]-=score[a];
    }
    void add(int x,int v){
	int a=find(x);
	score[a]+=v;
    }
    int get(int x){
	int res{};
	while(x!=p[x]) {
	    res+=score[x];
	    x=p[x];
	}
	res+=score[x];
	return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    //I will simply keep on grinding dsu tonight 
    //it is a very interseting algo
    cin>>n>>m;
    auto d = Dsu(n);
    for(int i=0;i<m;i++){
	string op;	
	cin>>op;
	if(op=="join"){
	    int x,y;
	    cin>>x>>y;
	    --x;--y;
	    d.join(x,y);
	}else if(op=="add"){
	    int x,v;
	    cin>>x>>v;
	    --x;
	    d.add(x,v);
	}else{
	    int x;
	    cin>>x;
	    --x;
	    cout<<d.get(x)<<'\n';
	}
    }

    return 0;
}

// 3 6 add 1 100 join 1 3 add 1 50 get 1 get 2 get 3
