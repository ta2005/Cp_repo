#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
	int k;
	cin>>k;
	int count2{};
	int count3{};
	for(int i=0;i<k;i++){
	    int c;cin>>c;
	    if(c>=2) count2++;
	    if(c>=3) count3++;
	}
	if(count2>=2 || count3 >= 1){
	    cout<<"YES\n";
	}else{
	    cout<<"NO\n";
	}
    }

    return 0;
}
