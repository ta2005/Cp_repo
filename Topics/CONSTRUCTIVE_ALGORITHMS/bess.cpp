#include <bits/stdc++.h> 

using namespace std; 
//I could make a vecotr fo acc and the n a variable to when statrt adding
int main() {
    int t;
    cin>>t;
    while(t--){
	int n,m,h;
	cin>>n>>m>>h;
	vector<int> v(n);
	for (int i=0;i<n;i++){
	    cin>>v[i];
	}
	vector<int> co=v;
	vector<pair<int,int>> op(n);
	int turn{};
	for (int i=0;i<m;i++){
	    int b,c;
	    cin>>b>>c;
	    op[i]={b,c};
	    co[b-1]+=c;
	    if ((co[b-1]-(turn!=0)*v[b-1])>h){
		turn=i;
	    }
	}
	for (int i=0;i<n;i++){
	    cout<<v[i]<<' ';
	}
	cout<<'\n';
    }
}

// 3 3 4 5 1 2 1 1 4 2 4 3 3 2 0 5 3 1 1 1 1 1 1 1 1 1 1 2 1 4 4 1 1 0 0 0 1 1 4 4 3 3 4 4
