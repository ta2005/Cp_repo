#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l = 0, r = v[n-1]-v[0];
    auto check = [&](int x){
	long long acc{};
	for(int i=0;i<n;i++){
	    acc+=(long long)max(v[n-1]-v[i]-x,0);
	}
	printf("acc:%lld x:%d\n",acc,x);
	return acc<=k;
    };
    //I will simply care about increase 
    //the best i can do is make all element eq to max
    //checking whether i can make the diff x 
    //meaning that for every item in the table i will 
    //increase it by 
    //max-arr[i]+x
    //
    while (l < r) {
	int mid = l + (r - l+1) / 2;
	if (check(mid)) {
	    r = mid;
	} else {
	    l = mid-1;
	}
    }
    cout<<l;
    return 0;
}

// 4 5 3 1 7 5
