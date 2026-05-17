#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	long long int n,f,a,b;
	cin>>n>>f>>a>>b;
	vector<long long> v(n+1);
	for(int i=1;i<=n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end());
	bool test=true;
	for(int i=1;i<=n && test;i++){
	    long long  con = min((v[i]-v[i-1])*a,b);
	    f-=con;
	    if(f<=0){
		test=false;
	    }
	}
	if(test){
	    cout<<"YES\n";
	}else{
	    cout<<"NO\n";
	}
    }
    

    return 0;
}

// 6 1 3 1 5 3 7 21 1 3 4 6 10 13 17 20 26 5 10 1 2 1 2 3 4 5 1 1000000000 1000000000 1000000000 1000000000 3 11 9 6 6 8 10 12 621526648 2585904 3566299 51789 61859 71998 73401 247675 298086 606959 663464 735972 806043 806459 919683
