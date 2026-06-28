#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    cout<<(n+1)/2<<'\n';
    for(int i=0;i<n;i+=2){
	cout<<v[i].second+1<<' ';	
    }
    cout<<'\n';
    cout<<(n/2)<<'\n';
    for(int i=1;i<n;i+=2){
	cout<<v[i].second+1<<' ';	
    }
    //output
    return 0;
}

// 3 1 2 1
