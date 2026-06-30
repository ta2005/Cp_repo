#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int k;
    cin>>n>>k;
    string res;
    int curr{};
    for(int i=0;i<n;i++){
	res+=('a'+curr);	
	curr++;
	curr%=k;
    }
    cout<<res;

    return 0;
}
