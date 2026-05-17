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
	vector<int> v(n);
	vector<int> pref(n+1);
	long long int sum{};
	for (int i=0;i<n;i++){
	    cin>>v[i];
	    sum+=v[i];
	}
	sort(v.begin(),v.end());
	auto it=upper_bound(v.begin(),v.end(),0);
	int nb=n-(it-v.begin());
	cout<<min((long long )nb,sum-nb+1)<<'\n';
    }

    return 0;
}

// 3 5 0 5 1 0 1 3 3 2 1 5 1 1 1 1 1
