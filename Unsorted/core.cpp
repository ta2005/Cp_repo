#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n);
	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    adj[--a].push_back(--b);
	    adj[b].push_back(a);
	}
	vector<bool>visited(n);
	vector<int>distance(n,0);
	queue<int>q;
	visited[0] = true;
	distance[0] = 0;
	q.push(0);
	while (!q.empty()) {
	    int s = q.front(); q.pop();
	    // process node s
	    for (auto u : adj[s]) {
		if (visited[u]) continue;
		visited[u] = true;
		distance[u] = distance[s]+1;
		q.push(u);
	    }
	}
	int nbr_blue{};
	for(int i=0;i<n;i++){
	    if(distance[i]%2==0){
		nbr_blue++;
	    }
	}
	int nbr_red=n-nbr_blue;
	if(nbr_blue<nbr_red){
	    cout<<nbr_blue<<'\n';
	    for(int i=0;i<n;i++){
		if(distance[i]%2==0){
		    cout<<i+1<<' ';
		}
	    }
	    cout<<'\n';
	}else{
	    cout<<nbr_red<<'\n';
	    for(int i=0;i<n;i++){
		if(distance[i]%2==1){
		    cout<<i+1<<' ';
		}
	    }
	    cout<<'\n';
	}
	// for(int i=0;i<n;i++){
	//     printf("the color of node %d is %s",i,distance[i]%2?"BLUE\n":"RED\n");
	// }
    }


    return 0;
}

// 2 4 6 1 2 1 3 1 4 2 3 2 4 3 4 6 8 2 5 5 4 4 3 4 1 1 3 2 3 2 6 5 6
