#include <bits/stdc++.h>
using namespace std;

//the pgcd of the group will be one if nad only if 
//there exists two elements such that their pgcd 
//is equal 1 meaning that they share no primes


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int>divisiors(1e5+1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
	long long int s;
	cin>>s;
	long long int start=s;
	for(long long int j=2;j*j<=start;j++){
	    if(s%j==0){
		divisiors[j]++;
		while(s%j==0){
		    s/=j;
		}
	    }
	    if(s>1){
		divisiors[s]++;
	    }
	}
    }
    cout<<*max_element(divisiors.begin(),divisiors.end());

    return 0;
}
