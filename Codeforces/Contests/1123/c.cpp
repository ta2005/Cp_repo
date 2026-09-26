#include<bits/stdc++.h>

using namespace std;

int main(){
    // this problem is about 
    // finding the subset 
    // that has the biggeset sum 
    // and it's gcd(a1..aj,x) is not 1
    // time will not suffice but here is my idea 
    // i will count the pgcd of each nbr with x
    // i will then group them by pgcd 
    // and do the trick of the seive 
    // by putting them in an arrary of length 2*10*5
    // and add them together 
    int t;
    cin>>t;
    while(t--){
	int n,x;
	cin>>n>>x;
	vector<long long>res(2*100000+5);
	vector<bool>visited(2*100000+5);
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	    res[gcd(v[i],x)]+=v[i];
	}
	for(int i=2;i<(2*100000+5);i++){
	    if(!visited[i]){
		for(long long j=(long long)i*i;j<(2*100000+5);j+=i){
		    visited[j]=true;
		    res[i]+=res[j];
		}
	    }
	}
	long long out{};
	for(int i=2;i<(2*100000+5);i++){
	    out=max(out,res[i]);
	}
	cout<<out<<'\n';
    }
}
