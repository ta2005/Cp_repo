#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int k;
    cin>>s>>k;
    for(int j=0;j<k;j++){
	for(int i=0;i<(int)s.size()-1;i++){
	    if(s[i]<s[i+1]){
		int a=s[i+1];
		s[i+1]=s[i];
		s[i]=a;
		break;
	    }
	}
    }
    cout<<s;
    return 0;
}
