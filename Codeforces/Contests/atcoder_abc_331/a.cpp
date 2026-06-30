#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;cin>>s;
    int testa=false;
    int testb=false;
    int testc=false;
    int i=0;
    for(i=0;i<(int)s.size();i++){
	if(s[i]=='A'){
	    testa=true;
	}
	if(s[i]=='B'){
	    testb=true;
	}
	if(s[i]=='C'){
	    testc=true;
	}
	if(testa&&testb&&testc){
	    break;
	}
    }
    cout<<i+1;

    return 0;
}
