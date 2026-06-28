#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string ham;
    cin>>ham;
    int b=0,s=0,c=0;
    for(auto i:ham){
	switch(i){
	    case 'B':b++;break;
	    case 'S':s++;break;
	    case 'C':c++;break;
	}
    }
    int nb,ns,nc;
    cin>>nb>>ns>>nc;
    int pb,ps,pc;
    cin>>pb>>ps>>pc;
    long long rp;cin>>rp;
    //I think two pointer should be good enought
    auto check = [&](long long x){
	long long  rb=max(x*b-nb,0LL);
	long long  rs=max(x*s-ns,0LL);
	long long  rc=max(x*c-nc,0LL);
	return ((rb*pb)+(rs*ps)+(rc*pc))<=rp;
    };
    long long l = 0LL, r = 2e14;
    while (l < r) {
	long long int mid = l + (r - l+1) / 2;
	if (check(mid)) {
	    l=mid;
	} else {
	    r = mid-1;
	}
    }
    cout<<l;
    return 0;
}
