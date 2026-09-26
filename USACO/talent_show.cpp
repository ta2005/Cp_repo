#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
    ifstream in("talent.in");
    ios::sync_with_stdio(false);
    in.tie(0);
    int n,w;
    in>>n>>w;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
	in>>v[i].first>>v[i].second;
    }
    vector<long long>res(1e6+5,INT_MAX);

    // i want to reach the biggest talent with the smallest weight
    res[0]=0;
    for(int i=0;i<n;i++){
	for(int j=1e6;j>=0;j--){
	    if(j+v[i].second<=1e6){
		res[j+v[i].second]=min(res[j+v[i].second],res[j]+v[i].first);
	    }
	}
    }
    long long r{};
    for(int i=0;i<1e6;i++){
	if(res[i]==INT_MAX || res[i]<w) continue;
	r=max(r,(1000*i/res[i]));
    }
    ofstream out("talent.out");
    out<<r;
    return 0;
}
