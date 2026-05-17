#include <algorithm>
#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("haybales.in");
    int n,q;
    in>>n>>q;
    vector<int> hay(n);
    for (int i=0;i<n;i++){
	in>>hay[i];
    }
    sort(hay.begin(),hay.end());
    ofstream out("haybales.out");
    for (int i=0;i<q;i++){
	int a,b;
	in>>a>>b;
	out<<upper_bound(hay.begin(),hay.end(),b)-lower_bound(hay.begin(),hay.end(),a)<<'\n';
    }
}
