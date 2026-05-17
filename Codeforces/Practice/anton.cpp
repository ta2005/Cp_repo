#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    //the index of the chacter to swap
    int res{-1};
    for(int i=0;i<n-1;i++){
	if((s[i]-'0')%2==0){
	    res=i;
	    if(s[i]<s[n-1]){
		break;
	    }
	}
    }
    if(res==-1){
	cout<<-1;
	return 0;
    }
    swap(s[res],s[n-1]);
    cout<<s;
    
    return 0;
}
