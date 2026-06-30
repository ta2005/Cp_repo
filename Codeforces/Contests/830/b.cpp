#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;cin>>n;
	string s;
	cin>>s;
	s+="hello";
	string res;
	for(int i=0;i<n;i++){
	    if(s[i+2]=='0' && s[i+3]!='0'){
		res+=('a'+(s[i]-'0')*10+(s[i+1]-'0')-1);
		i+=2;
	    }else{
		res+=('a'+(s[i]-'0')-1);
	    }
	}
	cout<<res<<'\n';
    }
    return 0;
}

// 9 6 315045 4 1100 7 1213121 6 120120 18 315045615018035190 7 1111110 7 1111100 5 11111 4 2606
