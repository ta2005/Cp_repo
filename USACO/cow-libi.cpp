#include <bits/stdc++.h> 

using namespace std; 

struct graz{
    int t;
    int x,y;
};

bool cmp(graz a,graz b){
    return a.t>b.t;
}

int main() {
    int n,g;
    cin>>n>>g;
    vector<graz> v(n);
    for (int i=0;i<n;i++){
	cin>>v[i].x;
	cin>>v[i].y;
	cin>>v[i].t;
    }
    sort(v.begin(),v.end(),cmp);
    int res{};
    for (int i=0;i<g;i++){
	graz cow;
	cin>>cow.x;
	cin>>cow.y;
	cin>>cow.t;
    }
}
