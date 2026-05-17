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
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end());
	//well the lenght of the string i v.end()->first+v.end()->second
	//but tabasii
	string res;
	bool test=true;
	for(int k=0;k<(v[0].first);k++){
	    res+='R';
	}
	for(int k=0;k<(v[0].second);k++){
	    res+='U';
	}
	for(int i=1;i<n && test;i++){
	    if (v[i].first<v[i-1].first || v[i].second<v[i-1].second){
		test=false;
		break;
	    }
	    for(int k=0;k<(v[i].first-v[i-1].first);k++){
		res+='R';
	    }
	    for(int k=0;k<(v[i].second-v[i-1].second);k++){
		res+='U';
	    }

	}
	if (test){
	    cout<<"YES\n"<<res<<'\n';
	}else{
	    cout<<"NO\n";
	}
    }

    return 0;
}

// 3 5 1 3 1 2 3 3 5 5 4 3 2 1 0 0 1 1 4 3
