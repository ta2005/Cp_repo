#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<char>> pref(n+4,vector<char>(26));
	for(int i=0;i<n;i++){
	    for(int j=0;j<26;j++){
		pref[i+2][j]=pref[i][j];
	    }
	    pref[i+2][s[i]-'a']++;
	}
	vector<char> odd(26);
	vector<char> even(26);
	if(n%2==1){
	    for(int i=0;i<n;i++){
		if(i%2==0){
		    vector<char> first_odd=pref[i+3];
		    vector<char> first_even=pref[i+4];
		    vector<char> last_odd=pref[n+3];
		    vector<char> last_even=pref[n+2];
		    vector<char> odd_diff(26);
		    vector<char> even_diff(26);
		    for(int j=0;j<26;j++){
			odd_diff[j]=last_odd[j]-first_odd[j];
			even_diff[j]=last_even[j]-first_even[j];
		    }
		    vector<char> bo=pref[i-1];
		    vector<char> be=pref[i-2];
		    for(int j=0;j<26;j++){
			odd_diff[j]+=bo[j];
			even_diff[j]=be[j];
		    }
		}else{
		    vector<char> first_odd=pref[i+4];
		    vector<char> first_even=pref[i+3];
		    vector<char> last_odd=pref[n+3];
		    vector<char> last_even=pref[n+2];
		    vector<char> odd_diff(26);
		    vector<char> even_diff(26);
		    for(int j=0;j<26;j++){
			odd_diff[j]=last_odd[j]-first_odd[j];
			even_diff[j]=last_even[j]-first_even[j];
		    }
		    vector<char> bo=pref[i-2];
		    vector<char> be=pref[i-1];
		    for(int j=0;j<26;j++){
			odd_diff[j]+=bo[j];
			even_diff[j]=be[j];
		    }
		    sort(odd_diff.begin(),odd_diff.end());
		    sort(even_diff.begin(),even_diff.end());
		    long long res=(n/2-odd.back()+n/2-even.back());
	    }
	}
	// sort(odd.begin(),odd.end());
	// sort(even.begin(),even.end());
	// long long res=(n/2-odd.back()+n/2-even.back());
	// cout<<res<<'\n';
	//if the lenght of the string is 
    }

    return 0;
}

// 10 1 a 2 ca 3 aab 5 ababa 6 acdada 9 ejibmyyju 6 bbccbc 6 abacba 5 bcbca 5 dcbdb
