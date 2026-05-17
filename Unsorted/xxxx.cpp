#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,x;
	cin>>n>>x;
	vector <int> v(n);
	long long sum{};
	for (int i=0;i<n;i++){
	    cin>>v[i];
	    sum+=v[i];
	}
	if (sum%x!=0){
	    cout<<n<<'\n';
	}else{
	    int l{};
	    while (l<n && v[l]%x==0){
		l++;
	    }
	    int r{n-1};
	    while (r>=0 && v[r]%x==0){
		r--;
	    }
	    if (l==n){
		cout<<-1<<'\n';
	    }else{
		cout<<max(r+0,n-l-1)<<'\n';
	    }
	} 
    }
    return 0;
}

// 3 3 3 1 2 3 3 4 1 2 3 2 2 0 6
//
//5 1 3 9 1 4 7 1 1 0 5 10000 10000 5000 5000 10000 0 8 2 0 1 0 1 0 1 0 1
