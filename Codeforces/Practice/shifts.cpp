#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
	string s;
	cin>>s;
	// this is about moving zeors to the front
	long long res{};
	int i=s.size()-1;
	int j=0;
	while(j<i){
	    while(i>0 && s[i]=='1'){
		i--;
	    }
	    j=min(j,i);
	    while(j<i && s[j]=='0'){
		j++;
	    }
	    if(s[j]=='1'){
		res+=(i-j+1);
	    }
	    i--;
	}
	cout<<res<<'\n';
    }
}

// 5 10 0000 11000 101011 01101001
