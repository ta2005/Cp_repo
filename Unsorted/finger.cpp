#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	long long int a,b,l;
	cin>>a>>b>>l;
	long long res{};
	long long acc{1};
	set<long long>div;
	for(int i=0;i<21;i++){
	    long long acc2{1};
	    if(acc>l) break;
	    for(int j=0;j<21;j++){
		if(acc2*acc>l) break;
		if(l%(acc*acc2)==0 && div.count(acc*acc2)==0){
		    res++;
		    div.insert(acc*acc2);
		}
		acc2*=b;
	    }
	    acc*=a;
	}
	cout<<res<<'\n';
    }

    return 0;
}

// 11 2 5 20 2 5 21 4 6 48 2 3 72 3 5 75 2 2 1024 3 7 83349 100 100 1000000 7 3 2 2 6 6 17 3 632043
