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
	vector<int>v(n);
	vector<vector<int>>st(31,vector<int>(n));
	for (int i=0; i<n; i++) {
	    cin>>v[i];
	}
	for(int i=0;i<n;i++){
	    st[0][i]=v[i];
	}	
	for(int i=1;i<=30;i++){
	    //1<<i is the lenght for the interval
	    for(int j=0;j+(1<<i)<=n;j++){
		st[i][j]=(st[i-1][j]&st[i-1][j+(1<<(i-1))]);
	    }
	}
	int q;cin>>q;
	for(int i=0;i<q;i++){
	    int l,k;
	    cin>>l>>k;
	    l--;
	    if(v[l]<k){
		cout<<-1<<' ';
		continue;
	    }
	    auto check = [&](int x){
		int range=x-l+1;
		int len=31-__builtin_clz(range);
		int calc = st[len][l] & st[len][x-(1<<len)+1];
		return calc>=k;
	    };
	    int  lf = l, rh = n-1;
	    int ans;
	    while (lf <= rh) {
		int mid = lf + (rh - lf) / 2;
		if (check(mid)) {
		    ans=mid;
		    lf = mid + 1;
		} else {
		    rh = mid-1;
		}
	    }
	    cout<<ans+1<<' ';
	}
	cout<<'\n';
    }

    return 0;
}

// 3 5 15 14 17 42 34 3 1 7 2 15 4 5 5 7 5 3 1 7 4 1 7 5 7 2 3 2 2 7 19 20 15 12 21 7 11 4 1 15 4 4 7 12 5 7
//
