#include <bits/stdc++.h> 

using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
	string s;
	int q;
	cin>>s>>q;
	for (int i=0;i<q;i++){
	    int j;
	    char v;
	    cin>>j>>v;
	    s[--j]=v;
	    if (s.find("1100")!=string::npos){
		cout<<"YES\n";
	    }else{
		cout<<"NO\n";
	    }
	}
    }
}

// 3 1100000 3 6 1 7 1 4 1 111010 4 1 1 5 0 4 1 5 0 0100 4 3 1 1 1 2 0 2 1
