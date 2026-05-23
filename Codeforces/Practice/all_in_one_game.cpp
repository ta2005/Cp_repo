#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,h,k;
	cin>>n>>h>>k;
	vector<int>v(n);
	vector<long long int>pref(n+1);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    pref[i+1]=pref[i]+v[i];
	}
	vector<int>next_max(n,INT_MIN);
	next_max[n-1]=v[n-1];
	vector<int>prev_min(n,INT_MAX);
	prev_min[0]=v[0];
	for (int i=1; i<n; i++) {
	    prev_min[i]=min(prev_min[i-1],v[i]);
	}
	for (int i=n-2; i>=0; i--) {
	    next_max[i]=max(next_max[i+1],v[i]);
	}
	long long div=(h-1)/pref[n];
	long long res{div*n+div*k};
	h-=div*pref[n];
	// printf("the accumulated is %lld\n",res);
	// now i could do bs on the min index i could stop at 
	// well it is rather obs i will sub the min 
	// integer in each range with the max in the other
	long long int l = 0, r = n;
	while (l < r) {
	    long long int mid = l + (r - l) / 2;
	    auto check = [&](int x){
		long long res{pref[x]};
		if(x>0 && x<n && prev_min[x-1]<next_max[x]){
		    res+=(next_max[x]-prev_min[x-1]);
		}
		return res>=h;
	    };
	    if (check(mid)) {
		r = mid;
	    } else {
		l = mid + 1;
	    }
	} 
	cout<<l+res<<'\n';
    }
    return 0;
}

// 6 5 10 1 4 2 3 5 3 5 10 1 4 2 3 7 3 3 10 2 1 2 3 2 5 3 2 1 3 18 5 1 2 3 4 10 10 1 1 2 2
