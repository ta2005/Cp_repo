#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<char>v(n);
    vector<pair<int,int>>u(52,{-1,-1});
    vector<pair<int,int>>l(52,{-1,-1});
    for (int i=0;i<n;i++){
	cin>>v[i];
	if (v[i]<='Z'){
	    if (u[v[i]-'A'].first==-1){ 
		u[v[i]-'A'].first=i;
	    }
	    u[v[i]-'A'].second=i;
	}else{
	    if (l[v[i]-'a'].first==-1){
		l[v[i]-'a'].first=i;
	    }
	    l[v[i]-'a'].second=i;
	}
    }
    int a =INT_MAX;
    for (int i=0;i<26;i++){
	if (u[i].second!=-1) a = min(a,u[i].second);
    }
    for (int i=0;i<26;i++){
	if (l[i].second!=-1) a = min(a,l[i].second);
    }
    //a is the min index such that after it all of the letters exist
    vector<pair<int,int>>l1(52,{-1,-1});
    vector<pair<int,int>>u1(52,{-1,-1});
    for (int i=a;i<n;i++){
	if (v[i]<='Z'){
	    if (u1[v[i]-'A'].first==-1){ 
		u1[v[i]-'A'].first=i;
	    }
	    u1[v[i]-'A'].second=i;
	}else{
	    if (l1[v[i]-'a'].first==-1){
		l1[v[i]-'a'].first=i;
	    }
	    l1[v[i]-'a'].second=i;
	}
    }
    int b=n-1;
    while(b>a){
	if (v[b]<='Z'){
	    if (u1[v[b]-'A'].first==b) break;
	}else{
	    if (l1[v[b]-'a'].first==b) break;
	}
	b--;
    }

    cout<<b-a+1;
    return 0;
}

// 3 AaA
