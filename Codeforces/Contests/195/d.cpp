#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int>

void dfs(int u,vector<bool> &vis,const vector<vector<int>> &g) {
    vis[u] = true;
    for (auto v: g[u]) {
        if (!vis[v]) {
            dfs(v,vis,g);
        }
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adf(n);
    vector<bool> visited(n,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adf[u-1].push_back(v-1);
        adf[v-1].push_back(u-1);
    }
    int c=0;
    int d=0;
    for(int i=0;i<n;i++){
        if(adf[i].size()>1) d++;
        if(!visited[i]){
            if(adf[i].size()==0){
                cout<<"Brain Melt"<<endl;
                return;
            }
            c++;
            dfs(i,visited,adf);
        }
    }
    if(c>1 || d>1) cout<<"Many"<<endl;
    else cout<<2<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}
