#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
	vector<pair<int,int>> v(n);
	int j{};
	int m;
	char c;
	cin>>m>>c;
	int l=0,r=0;
	bool test=false;
	while (r<n){
	    if (s[r]==c){
		if(s[l]!=c){
		    l=r;
		}
		r++;
	    }else{
		if (s[l]==c){
		    v[j++]={l,r};
		    l=r;
		}
		r++;
	    }
	}
	if (s[r-1]==c){
	    v[j++]={l,r};
	}
	for (auto i:v){
	    cout<<i.first<<' '<<i.second<<endl;
	}
    }
} 
// 24 tallellllelllllllllelll 1  1 l
// 6 allala 1 1 l
