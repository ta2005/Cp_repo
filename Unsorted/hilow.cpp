#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n;
    ifstream in("cardgame.in");
    in>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++){
	in>>v[i];
    }
    sort(v.rbegin(),v.rend());
    int count{};
    for (int i=0;i<n;i++){
	count+=v[i]<=(i+1);
    }
    cout<<count;
}
// 5 7 1 400 2 2
