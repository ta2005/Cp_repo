#include <bits/stdc++.h> 

using namespace std; 

struct milking{
    int x;
    int y;
};

bool cmp(const milking&a,const milking&b){
    return a.y<b.y;
}

int main() {
    ifstream in("pairup.in");
    int n;
    in>>n;
    vector<milking> v(n);
    for (int i=0;i<n;i++){
	in>>v[i].x>>v[i].y;
    }
    sort(v.begin(),v.end(),cmp);
    int l=0;
    int r=n-1;
    int res{};
    while(l<r){
	res=max(res,v[l].y+v[r].y);
	int m=min(v[l].x,v[r].x);
	v[l].x-=m;
	v[r].x-=m;
	if (v[r].x==0){
	    r--;
	}
	if (v[l].x==0){
	    l++;
	}
    }
    if (l==r){
	res=max(res,2*v[l].x);
    }
    ofstream out("pairup.out");
    out<<res;
}
