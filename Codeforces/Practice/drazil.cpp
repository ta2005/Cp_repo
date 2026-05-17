#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>freq(10);
    for(int i=0;i<n;i++){
	char d;
	cin>>d;
	for(int j=2;j<=(d-'0');j++){
	    freq[j]++;
	}
    }
    string res;
    // sort(freq.begin(),freq.end(),std::greater<int>());
    for(int i=9;i>=0;i--){
	if(freq[i]==0) continue;
	for(int j=0;j<freq[i];j++) res+=+'0'+i;
    }
    cout<<res;
    return 0;
}
