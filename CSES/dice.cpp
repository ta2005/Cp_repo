#include <bits/stdc++.h>
using namespace std;

pair<int,int> calc(int a,int b){
    vector<bool>v(6,true);
    v[a-1]=false;
    v[b-1]=false;
    v[6-a]=false;
    v[6-b]=false;
    int j{};
    pair<int,int> res;
    for (int i=0;i<6;i++){
	if (v[i]){
	    if (j==0){
		res.first=i+1;
		j++;
	    }else{
		res.second=i+1;
	    }
	}
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int prev;
    cin>>prev;
    vector<int>v(n);
    bool test=true;
    for (int i=0;i<n && test;i++){
	int a,b;
	cin>>a>>b;
	auto wa=calc(a,b);
	if (!(wa.first==prev || wa.second==prev)){
	    cout<<"NO";
	    return 0;
	}
    }
    cout<<"YES";

    return 0;
}

// 3 6 3 2 5 4 2 4
