#include <bits/stdc++.h>
using namespace std;

//so overflow
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    queue< int>q;
    q.push(n);
    vector<int>distance(1e5,-1);
    distance[n]=0;
    while(!q.empty()){
	int node=q.front();q.pop();
	if(node==m){
	    cout<<distance[m];return 0;
	}
	if(node>1 && distance[node-1]==-1 ){
	    q.push(node-1);
	    distance[node-1]=distance[node]+1;
	}
	if(node*2<1e5 && distance[node*2]==-1){
	    q.push(node*2);
	    distance[node*2]=distance[node]+1;
	}
    }
    //this is probalbly a graph from 
    return 0;
}
