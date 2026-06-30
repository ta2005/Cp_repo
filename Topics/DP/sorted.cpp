#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,q;
	cin>>n>>q;
	string a,b;
	cin>>a>>b;
	vector<vector<int>> pref1(n+1,vector<int>(26));
	vector<vector<int>> pref2(n+1,vector<int>(26));
	for (int i=0;i<n;i++){
	    pref1[i+1][a[i]-'a']++;
	    pref2[i+1][b[i]-'a']++;
	}
	for(int i=0;i<q;i++){
	    int l,r;
	    cin>>l>>r;
	    long long res{};
	    long long count{};
	    for (int j=0;j<26;j++){
		count+=min(pref1[r][j],pref2[l-1][i]);
	    }
	    res=(r-l+1)-count;
	    cout<<res<<'\n';
	}
    }

    return 0;
}

// 3 5 3 abcde edcba 1 5 1 4 3 3 4 2 zzde azbe 1 3 1 4 6 3 uwuwuw wuwuwu 2 4 1 3 1 6
