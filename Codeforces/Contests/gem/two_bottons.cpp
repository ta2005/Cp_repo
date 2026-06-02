#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //this is technically a shortest distance 
    //where for earch interger n it has two neigh n*2 and n-1
    int n,m;
    cin>>n>>m;
    queue<int>q;
    vector<int>dis(1e5*4,INT_MAX);
    q.push(m);
    dis[m]=0;
    while(!q.empty()){
	int u=q.front();q.pop();
	if(u%2==0){
	    if(dis[u/2]==INT_MAX){
		q.push(u/2);
		dis[u/2]=min(dis[u/2],dis[u]+1);
	    }
	}
	if(dis[u+1]==INT_MAX){
	    q.push(u+1);
	    dis[u+1]=min(dis[u+1],dis[u]+1);
	}
	if(u==n){
	    cout<<dis[u];return 0;
	}
    }
    return 0;
}
