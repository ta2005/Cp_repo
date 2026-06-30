#include <bits/stdc++.h>

using namespace std;

bool calc(vector<int>&v,int t,long long x){
    long long res{};
    for (auto i:v){
	res+=(x/i);
	if (res>=t){
	    return true;
	}
    }
    // cout<<res<<' '<<x<<endl;
    return res>=t;
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
	cin >> v[i];
    }
    long long a=0;
    long long b=LONG_LONG_MAX;
    while (a<b){
	long long mid=a+(b-a)/2;
	if (calc(v,t, mid)){
	    b=mid;
	}else{
	    a=mid+1;
	}
    }
    cout<<a;
}

// 3 7 3 2 5
//10 10 6 6 4 3 4 9 3 2 6 10
//1 1000000000 1000000000
