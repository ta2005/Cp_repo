#include <bits/stdc++.h>
using namespace std;

//these are the unvisited nodes
vector<set<int>>v(200005);
set<int>s;
int n,m;

//the dfs should return the size of the connected comp
int dfs(int node){
    vector<int>to_visit;
    s.erase(node);
    int acc{1};
    for(auto u:s){
	//i can't go to this node 
	if(v[node].count(u)==0){
	    to_visit.push_back(u);
	}
    }
    for(auto u:to_visit){
	s.erase(u);
    }
    for(auto u:to_visit){
	acc+=dfs(u);
    }
    return acc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
	int x,y;
	cin>>x>>y;
	v[--x].insert(--y);
	v[y].insert(x);
    }
    vector<int>res;
    for(int i=0;i<n;i++){
	s.insert(i);	
    }
    for(int i=0;i<n;i++){
	if(s.count(i)!=0){
	    s.erase(i);
	    res.push_back(dfs(i));
	}
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(auto i:res){
	cout<<i<<' ';
    }


    return 0;
}

// 5 5 1 2 3 4 3 2 4 2 2 5
