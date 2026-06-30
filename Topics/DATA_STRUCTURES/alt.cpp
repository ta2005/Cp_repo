#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	string s;
	cin>>s;
	int l=0;
	int r=s.size();
	int n = s.size();
	while(l<n-1 && s[l]!=s[l+1]){
	    l++;
	}
	while(r>0 && s[r]!=s[r-1]){
	    r--;
	}
	cout<<s.substr(l,r-l+1)<<endl;
    }

    return 0;
}

// 8 abbaba aaaaa bababba ab abbaabba bbb ababa aabb
