#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int t;
    cin>>t;
    while (t--){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if ((a==b) && (c==d) && (a==c)){
	    cout<<"YES"<<'\n';
	}else{
	    cout<<"NO"<<'\n';
	}
    }
}

// 7 1 2 3 4 1 1 1 1 2 2 2 2 1 2 1 2 1 1 5 5 5 5 5 5 4 10 5 9
