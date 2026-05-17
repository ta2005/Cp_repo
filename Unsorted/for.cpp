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
	int first=-1;
	for(int i=0;i<s.size();i++){	    
	    if(s[i]=='1'){
		first=i;
		break;
	    }
	}
	if(first==-1){
	    cout<<"No\n";
	}else{
	    int second=-1;
	    for(int i=first+1;i<s.size();i++){	    
		if(s[i]=='1'){
		    second=i;
		    break;
		}
	    }
	    if(second==-1){
		cout<<"No\n";
	    }else{
		cout<<"Yes\n";
	    }
	}
    }
    return 0;
}

// 2 0001 0101
