#include <bits/stdc++.h>
using namespace std;
//ai-aj == i-j is eq to ai-i == aj-i
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int> v(n);
	map<int,int>m;
	long long count{};
	for (int i=0;i<n;i++){
	    cin>>v[i];
	    v[i]-=i+1;
	    count+=m[v[i]];
	    m[v[i]]++;
	}
	cout<<count<<'\n';
    }
    
    return 0;
}

// 4 6 3 5 1 4 6 6 3 1 2 3 4 1 3 3 4 6 1 6 3 4 5 6
