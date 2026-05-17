#include <bits/stdc++.h> 

struct f {
    int money,fr;   
    bool operator<(const f& b){
	return this->money<b.money;
    }
};

using namespace std; 


int main() {
    int n,d;
    cin>>n>>d;
    vector<f> v(n);
    for (int i=0;i<n;i++){
	cin>>v[i].money>>v[i].fr;
    }
    sort(v.begin(),v.end());
    vector<long long > pref(n+1);
    for (int i=0;i<n;i++){
	pref[i+1]=pref[i]+v[i].fr;
    }
    long long res{};
    int l=0;
    int r=0;
    while (r<(n)){
	while((v[l].money+d)<=(v[r].money)) l++;
	res=max(res,pref[r+1]-pref[l]);
	r++;
    }
    cout<<res;
}

// 4 5 75 5 0 100 150 20 75 1
// 5 100 0 7 11 32 99 10 46 8 87 54
