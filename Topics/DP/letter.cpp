#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int t;
    cin>>t;
    while (t--) {
	int n;
	cin>>n;
	unordered_map<string,long long> a;
	long long res{};
	for (int i=0;i<n;i++){
	    string s;
	    cin>>s;
	    a[s]++;
	    for (int j='a';j<='k';j++){
		if (j==s[0]) continue;
		string test = s;
		test[0]=j;
		res+=a[test];
	    }
	    for (int j='a';j<='k';j++){
		if (j==s[1]) continue;
		string test = s;
		test[1]=j;
		res+=a[test];
	    }
	}
	cout<<res<<'\n';
    }
}

// 4 6 ab cb db aa cc ef 7 aa bb cc ac ca bb aa 4 kk kk ab ab 5 jf jf jk jk jk
