#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<bool>taken(m);
    for (int i=0;i<n;i++){
	int l;
	cin>>l;
	int choice{};
	int j{};
	for (j=0;j<l;j++){
	    int a;
	    cin>>a;
	    if (!taken[a-1]){
		taken[a-1]=true;
		choice=a;
		break;
	    }
	}
	j++;
	for (;j<l;j++){
	    int a;
	    cin>>a;
	}
	cout<<choice<<'\n';
    }
     
    return 0;
}
// 4 5 3 3 1 2 3 3 2 1 2 2 3 4 2 5 3 1
