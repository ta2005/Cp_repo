#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t,k;
    cin>>n>>t>>k;
    //let p be the prefix sum
    //since the only poss values are 0 and 1 
    //the pref in increasing so bs makes sense
    //the number of zeros in an interval[l,r] is equal 
    //to r-l+1-ans
    int l=1;
    int r=n;
    vector<int>v(n+1);//this is the number of zeors in this interval
    for (int i=0;i<20;i++){	 
	std::cout<<l<<r<<'\n';
	std::cout.flush();
	int ans;
	cin>>ans;
	//this is the number of zeors in this interval
	int count=(l-r+1)-ans;
    }
	//    int l = 0, r = n;
	//    while (l < r) {
	// int mid = l + (r - l) / 2;
	// if (check(mid)) {
	//     l = mid + 1;
	// } else {
	//     r = mid;
	// }
	//    }
    return 0;
}
