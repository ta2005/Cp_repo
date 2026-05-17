#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>v(n);
	cin>>v[0];
	int m=0;
	for(int i=1;i<n;i++){
	    cin>>v[i];
	    if(v[i]<v[m]){
		m=i;
	    }
	}
	// cout<<'m'<<m<<'\n';
	if (std::is_sorted(v.begin()+m,v.end())){
	    cout<<m<<'\n';
	}else{
	    cout<<-1<<'\n';
	}
    }

    return 0;
}
