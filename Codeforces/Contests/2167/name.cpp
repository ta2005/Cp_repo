#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int t;
    cin>>t;
    while (t--){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if (a==b){
	    cout<<"YES"<<'\n';
	}else{
	    cout<<"NO"<<'\n';
	}
    }
}
// 5 7 humitsa mitsuha 4 orhi hori 6 aakima makima 6 nezuqo nezuko 6 misaka mikasa
