#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n,n-1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
	    //this means that no group can contain both 
	    //and b
	    if(a>b){
		swap(a,b);
	    }
	    --a;
	    --b;
	    v[a]=min(b-1,v[a]);
        }
	for(int i=n-2;i>=0;i--){
	    v[i]=min(v[i],v[i+1]);
	}
	long long res{};
        for (int i = 0; i < n; i++) {
            int count = v[i]-i+1;
            res += (long long)count;
        }
        cout << res << '\n';
    }
    return 0;
}

// 2 3 2 1 3 2 3 4 2 1 2 2 3
