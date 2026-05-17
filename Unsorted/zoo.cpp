#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
	string s;
	cin>>s;
	int res=s.size();
	int l=s.size();
	for (int i=0;i<(l-1);i++){
	    if (s[i]=='B' && s[i+1]=='B'){
		res-=2;
		i++;
	    }else if (s[i]=='A' && s[i+1]=='B'){
		int l=i++;
		int r=i;
		while (l>=0 && r<l && ( (s[l]=='A' && s[r]=='B') || (s[l]=='B' && s[r]=='B'))){
		    l--;
		    r++;
		}
	    }
	}
    }

    return 0;
}
