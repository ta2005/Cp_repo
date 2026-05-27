#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;cin>>n;
	for(int i=31;i>=0;i--){
	    if((n&(1<<i))!=0){
		cout<<(1<<i)<<'\n';
		break;
	    }
	}
    }
    return 0;
}

// 4 1 4 5 120240229
