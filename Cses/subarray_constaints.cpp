#include <bits/stdc++.h>
using namespace std;

bool possible=true;

void dfs(int node,vector<vector<pair<long long,long long>>>&adj,vector<long long>&pref,vector<bool>&vis){
    if(!possible)return;
    for(auto u:adj[node]){
	if(!vis[u.first]){
	    vis[u.first]=true;
	    pref[u.first]=pref[node]+u.second;
	    dfs(u.first,adj,pref,vis);
	}else if(pref[u.first]!=pref[node]+u.second){
	    possible=false;
	    break;
	}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<long long>pref(n+1);
    //my task is to calc the prefix sum
    vector<vector<pair<long long,long long>>>adj(n+1);
    // i will put pref[0]=0
    for(int i=0;i<m;i++){
	int l,r,s;	
	cin>>l>>r>>s;
	adj[--l].push_back({r,s});
	adj[r].push_back({l,-s});
    }
    vector<bool>vis(n+1);
    for(int i=0;i<n;i++){
	vis[i]=true;
	dfs(i,adj,pref,vis);
	if(!possible)break;
    }
    if(!possible){
	cout<<"NO\n";
    }else{
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
	    cout<<pref[i]-pref[i-1]<<' ';
	    
	}
    }
    //let this be the first node i will have to go through
    return 0;
}

// 5 3 1 3 3 3 5 3 4 4 -1
