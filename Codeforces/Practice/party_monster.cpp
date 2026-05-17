#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int open{};
	int closed{};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    char c;
	    cin>>c;
	    if(c==')'){
		closed++;
	    }else{
		open++;
	    }
	}
	if(open==closed){
	    cout<<"YES\n";
	}else{
	    cout<<"NO\n";
	}
    }

    return 0;
}
