#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	//i will need fo find integer a and b a>b such that a = b*2(a-b)
	sort(v.begin(),v.end());
	long long sum{};
	for(int i=n-1;i>=0;i--){
	    for(int j=0;j<32;j++){
		int pow=1<<j;
		int calc=v[i]-v[i]/pow;
		if(v[i]<(pow) || v[i]%pow!=0 ||calc!=j)continue;
		auto a = lower_bound(v.begin(),v.begin()+i, v[i]/pow);
		auto b = upper_bound(v.begin(),v.begin()+i, v[i]/pow);
		int nbr=b-a;
		if (nbr!=0){
		    sum+=nbr;
		}
	    }
	}
	cout<<sum<<'\n';
    }
    return 0;
}

// 5 1 2 4 3 1 3 2 2 1000 1000 3 1 1 1 19 2 4 1 6 2 8 5 4 2 10 5 10 8 7 4 3 2 6 10
