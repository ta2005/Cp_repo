#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n,k;
    cin>>n>>k;
    //this graph must have a cycle
    //so my job is to find the lenght for cycle and at which 
    //index it starts
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
	v[i]--;
    }
    vector<int>dis(n,-1);
    queue<int>q;
    q.push(0);
    dis[0]=0;
    int start{};
    while(!q.empty()){
	int u=q.front();q.pop();
	if(dis[v[u]]!=-1){
	    start=v[u];
	    break;
	}
	dis[v[u]]=dis[u]+1;
	q.push(v[u]);
    }
    vector<int>cycle;
    cycle.push_back(start);
    int u=v[start];
    while(u!=start){
	cycle.push_back(u);
	u=v[u];
    }
    if(k<=dis[start]){
	for(int i=0;i<n;i++){
	    if(dis[i]==k){
		cout<<i+1<<'\n';
	    }
	}
    }else{

	int index=((k-dis[start])%cycle.size()+cycle.size())%cycle.size();
	cout<<cycle[index]+1<<'\n';
    }
    

    return 0;
}
// 4 5 3 2 4 1
