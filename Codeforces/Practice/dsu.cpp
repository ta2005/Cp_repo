#include <bits/stdc++.h>
#include <cassert>
using namespace std;

//ok this should be generic 
//and i should put it in a snippet 
//or template
class Dsu {
  private:
    vector<int> p;
    vector<int> s;

  public:
    Dsu(int n) {
	p.resize(n);
	iota(p.begin(),p.end(),0);
	s.assign(n,1);
    }

    int find(int x){
	assert(x>=0 && x<(int)p.size());
	if(x==p[x]) return x;
	return p[x] = find(x);
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
};

// this is the codeforces edu problem
// just to implment a dsu
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
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
	    int a,b;
	    cin>>a>>b;
	    --a;--b;
	    cout<<(d.find(a)==d.find(b)?"YES\n":"NO\n");
	}
    }

    return 0;
}
