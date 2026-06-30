#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    map<string,int>fr;
    vector<int>p(n);
    for (int i=0;i<n;i++){
	cin>>p[i];
    }
    sort(p.begin(),p.end());
    for (int i=0;i<m;i++){
	string s;
	cin>>s;
	fr[s]++;
    }
    vector<pair<int,string>> v(m);
    int j{};
    for (auto i:fr){
	v[j++]={i.second,i.first};
    }
    sort(v.begin(),v.end());
    j=0;
    long long res2{};
    long long res{};
    for (int i=m-1;i>=0;i--){
	res+=(v[i].first*p[j++]);
    }
    j=n-1;
    for (int i=m-1;i>=0;i--){
	res2+=(v[i].first*p[j--]);
    }
    cout<<res<<' '<<res2;
    return 0;
}

// 5 3 4 2 1 10 5 apple orange mango
// 6 5 3 5 1 6 8 1 peach grapefruit banana orange orange
