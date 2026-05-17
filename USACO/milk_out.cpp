#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("pairup.in");
    int n;
    in>>n;
    vector<pair<int,int>> v(n);
    int index=0;
    long long m{};
    for (int i=0;i<n;i++){
	in>>v[i].second>>v[i].first;
	m+=v[i].second;
    }
    sort(v.begin(),v.end());
    long long res{};
    int i=0;
    int j=n-1;
    int counter{};
    while ((counter)<(m/2)){
	res+=v[j-(v[j].second>=1)].first;
	res+=v[i+(v[i].second>=1)].first;
	counter+=2;
    }
    ofstream out("pairup.out");
    out<<res;
}
