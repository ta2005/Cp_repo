#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
	int a,b;
	cin>>a>>b;
	v[i].first=a;
	v[i].second=b;
    }
    // sort(v.begin(),v.end());
    long long a{};
    long long g{};
    vector<char>res(n);
    for(int i=0;i<n;i++){
	if(abs(a+v[i].first-g)<=500){
	    a+=v[i].first;
	    res[i]='A';
	}else{
	    g+=v[i].second;
	    res[i]='G';
	}
    }
    if(abs(a-g)>500){
	cout<<-1;
	return 0;
    }
    for(auto c:res){
	cout<<c;
    }
    return 0;
}

// 2 1 999 999 1
