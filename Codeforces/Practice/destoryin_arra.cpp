#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Dsu {
  private:
    vector<int> p;
    vector<int> s;
    vector<long long> sz;
    vector<long long>res;
    long long m=0;

  public:
    Dsu(int n) {
	p.assign(n,-1);
	s.assign(n,1);
	sz.assign(n,0);
    }
    // the rep of each ele is the smallest elem 
    // in it
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
	sz[a]+=sz[b];
	p[b]=a;	
    }

    void add(int x,int v){
	p[x]=x;
	sz[x]=v;
	res.push_back(m);
	if(x>0){ 
	    if(p[x-1]!=-1){
		join(x,x-1);
	    }
	}
	if(x<(int)(p.size()-1)){
	    if(p[x+1]!=-1){
		join(x,x+1);
	    }
	}
	m=max(m,sz[find(x)]);
    }
    void finish(){
	for(int i=(int)(res.size()-1);i>=0;i--){
	    cout<<res[i]<<'\n';
	}
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>op(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    //we could do the array in reverse 
    //meaning that removal from the array 
    //is the same as insertion
    for(int i=0;i<n;i++){
	cin>>op[i];
	op[i]--;
    }
    Dsu d = Dsu(n);
    for(int i=n-1;i>=0;i--){
	d.add(op[i],v[op[i]]);	
    }
    d.finish();


    return 0;
}

// 4 1 3 2 5 3 4 1 2
