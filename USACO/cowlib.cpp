#include <bits/stdc++.h> 

using namespace std; 

struct all{
    int x,y,t;
};

bool cmp(const all&a,const all&b){
    return a.t<b.t;
}

long long distance (all a, all b){
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx*dx + dy*dy;
}
int main() {
    int g,n;
    cin>>g>>n;
    vector<all>v(g);
    for (int i=0;i<g;i++){
	cin>>v[i].x>>v[i].y>>v[i].t;
    }
    sort(v.begin(),v.end(),cmp);
    vector<all>c(n);
    for (int i=0;i<n;i++){
	cin>>c[i].x>>c[i].y>>c[i].t;
    }
    int res{};
    for (int i=0;i<n;i++){
	auto k=lower_bound(v.begin(),v.end(),c[i],cmp);
	bool lower=true;
	bool upper=true;
	if (k!=v.end()){
	    upper=distance(*k,c[i])<=((k->t-c[i].t)*(k->t-c[i].t));
	}
	if (k!=v.begin()){
	    auto j=k-1;
	    lower=distance(*j,c[i])<=((j->t-c[i].t)*(j->t-c[i].t));
	}
	res+=lower&&upper;
    }
    cout<<res;
}
// 2 4 0 0 100 50 0 200 0 50 50 1000 1000 0 50 0 200 10 0 170
