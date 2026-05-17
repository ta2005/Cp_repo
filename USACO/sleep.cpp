#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream in("sleepy.in");
    int n;
    in>>n;
    vector<int>v(n);
    for (int i = 0;i<n;i++){
	in>>v[i];
    } 
    int r = n-2;
    while (r>=0 && v[r]<v[r+1]){
	r--;
    }
    ofstream out("sleepy.out");
    out<<r+1;

    return 0;
}
