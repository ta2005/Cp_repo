#include <bits/stdc++.h>
using namespace std;

struct fight{
    int l,r,x;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;    
    cin>>n>>m;
    vector<int>v(n+1);
    vector<fight>f(m);
    for(int i=0;i<m;i++){
	cin>>f[i].l>>f[i].r>>f[i].x;
	if(v[f[i].l]==0) v[f[i].l]=f[i].x;
	if(v[f[i].r]==0) v[f[i].r]=f[i].x;
    }
    int l1=f[0].l;
    int prev=f[0].x;
    for(int i=l1;i<=n;i++){
	if (v[i]!=0) prev=v[i];
	v[i]=prev;
    }
    prev=f[0].x;
    for(int i=l1-1;i>=0;i--){
	if (v[i]!=0) prev=v[i];
	v[i]=prev;
    }
    for(int i=0;i<(m-1);i++){
	v[f[i].x]=f[i+1].x;
    }

    int last=f[m-1].x;
    sort(f.begin(),f.end(),[](auto a,auto b){
	    return a.l<=b.l;
	}
    );
    for(int i=0;i<m-1;i++){
	v[f[i].x]=v[f[i+1].x];
    }
    v[last]=0;
    for(int i=1;i<=n;i++){
	cout<<v[i]<<' ';
    }
    return 0;
}

// 8 4 3 5 4 3 7 6 2 8 8 1 8 1
