#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    string res;
    for(int i=0;i<s.size();i++){
	if( s[i]>='0' && s[i]<= '9'){
	    res+=s[i];
	}
    }
    cout<<res;

    return 0;
}
