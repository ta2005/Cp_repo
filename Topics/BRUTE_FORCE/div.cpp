#include <bits/stdc++.h>
using namespace std;

vector<long long>res;
void sieve(){
    const int n=1e4;
    vector<bool>is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(long long int i=2;i<=n;i++){
	if(is_prime[i]){
	    for(long long int j=i*i;j<=n;j+=i){
		is_prime[j]=false;
	    }
	}
    }
    for(int i=0;i<=n;i++){
	if(is_prime[i]) res.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    sieve();
    while(t--){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	bool test=true;
	bool change=false;
	auto a=*max_element(v.begin(),v.end());
	auto b=*min_element(v.begin(),v.end());
	for(auto p:res){
	    long long count{};
	    for(int i=0;i<n ;i++){
		while(v[i]%p==0){
		    change=true;
		    count++;
		    v[i]/=p;
		}
	    }
	    if(count%n!=0){
		test=false;
		break;
	    }
	}
	if(!change && a!=b){
	    cout<<"NO\n";
	}else if(test){
	    cout<<"YES\n";
	}else{
	    cout<<"NO\n";
	}
    }
    return 0;
}

// 7 5 100 2 50 10 1 3 1 1 1 4 8 2 4 2 4 30 50 27 20 2 75 40 2 4 4 3 2 3 1
