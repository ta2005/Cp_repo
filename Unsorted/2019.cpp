#include <bits/stdc++.h>
using namespace std;
//
// a+b % c
// a%c+b%c
// c = a + (10**5)*b
// c==r%m
// a==r%m
//
constexpr long long mod = 2019;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    vector<long long> pref(s.size()+1);
    map<int,int> m;
    m[0]++;
    int pow = 1;
    int n = s.size();
    long long int res{};
    for(int i=s.size()-1;i>=0;i--){
    	pref[n-i]=pref[n-i-1]+(s[i]-'0')*pow;
	pow= (pow*10)%mod;
	pref[n-i]%=mod;
	res+=m[pref[n-i]];
	m[pref[n-i]]++;
    }
    cout<<res;
    return 0;
}

// 1817181712114
