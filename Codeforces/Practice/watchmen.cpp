#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    set<pair<int,int>>s;
    map<int,int>mx;
    map<int,int>my;
    map<pair<int,int>,int>pos;
    long long count{};
    for(int i=0;i<n;i++){
	int x,y;
	cin>>x>>y;
	mx[x]++;
	my[y]++;
	pos[{x,y}]++;
    }
    for(auto i:mx){
	count+=(long long)(i.second-1)*(i.second)/2;
    }
    for(auto i:my){
	count+=(long long)(i.second-1)*(i.second)/2;
    }
    for(auto i:pos){
	count-=(long long)(i.second-1)*(i.second)/2;
    }
    cout<<count;
    return 0;
}

// 3 1 1 7 5 1 5
//
//10 46 -55 46 45 46 45 83 -55 46 45 83 -55 46 45 83 45 83 45 46 -55
