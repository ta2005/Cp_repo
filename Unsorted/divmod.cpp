#include <bits/stdc++.h> 

using namespace std; 

int main() {
    string s;
    cin>>s;
    constexpr int mod=2019;
    vector<int> pref(s.size()+1);
    int pow=1;
    map<int,int> m;
    m[0]++;
    int res{};
    int len=s.size();
    for (int i=0;i<s.size();i++){
	pref[i+1]=(pref[i]+pow*(s[len-i-1]-'0'))%mod;
	pow=(pow*10)%mod;
	res+=(m[pref[i+1]]++);
    }
    cout<<res;
}
