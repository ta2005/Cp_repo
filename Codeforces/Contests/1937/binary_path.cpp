#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
	int n;
	cin>>n;
	string s1;
	string s2;
	cin>>s1>>s2;
	//the grass hopper must do one jump 
	//i need ot choose the one that minizies the cost
	//so i need to test whether 
	int pos{n-1};
	for(int i=0;i<n-1;i++){
	    if(s2[i]=='0' && s1[i+1]=='1'){
		pos=i;
		break;
	    }
	}
	// cout<<pos<<'\n';
	string min=s1.substr(0,pos+1)+s2.substr(pos);
	cout<<min<<'\n';
	long long res{};
	for(int i=pos;i>=0;i--){
	    if(min[i+1]!=s2[i]){
		break;
	    }else{
		res++;
	    }
	}
	cout<<res<<'\n';
    }

    return 0;
}

// 3 2 00 00 4 1101 1100 8 00100111 11101101
// 1 8 00100111 11101101
