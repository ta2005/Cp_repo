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
	vector<vector<int>>acc(26);
	int n=s.size();
	for(int i=0;i<n;i++){
	    acc[s[i]-'a'].push_back(i+1);
	}
	vector<int>res;
	if(s[0]>=s[n-1]){
	    int pos=s[0]-'a';
	    while(true){
		for(auto i:acc[pos]){
		    res.push_back(i);
		}
		if((pos+'a')==s[n-1]){
		    break;
		}
		pos--;
	    }
	} else{
	    int pos=s[0]-'a';
	    while(true){
		for(auto i:acc[pos]){
		    res.push_back(i);
		}
		if((pos+'a')==s[n-1]){
		    break;
		}
		pos++;
	    }
	}
	long long cost{};
	for(int i=1;i<(int)res.size();i++){
	    cost+=abs(s[res[i]-1]-s[res[i-1]-1]);
	}
	cout<<cost<<' '<<res.size()<<'\n';
	for(auto i:res){
		cout<<i<<' ';
	}
	cout<<'\n';
	// if the start is bigger i simply go the throught all the ones that 
	// are smaller then me
    }
    return 0;
}

// 6 logic codeforces bca aaaaaaaaaaa adbaadabad to
