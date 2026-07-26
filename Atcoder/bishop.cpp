#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    // a naieve bfs will MLE
    // so i need smth better 
    // maybe rather than marking every square 
    // i store the staring and ending pos of the diag
    return 0;
}
