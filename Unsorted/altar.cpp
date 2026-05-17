#include <bits/stdc++.h>
using namespace std;

vector<int>fib = {1,    2,     3,     5,     8,     13,    21,    34,
    55,   89,   144,   233,   377,   610,   987,   1597,  2584,
    4181, 6765, 10946, 17711, 28657, 46368, 75025};


//thi is for alayze 
//a number is winning only and if there exits 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<bool>v(1e5+2);
    for(auto i:fib){
	v[i]=true;
    }
    for(int i=2;i<(int)v.size();i++){
	if (v[i])continue;
	for(auto j:fib){
	    if(j>i) break;
	    //this mean my opponent will loose next turn
	    if(v[i-j]==false) {
		v[i]=true;
		break;
	    }
	}
    }
    while (t--) {
	int n;
	cin >> n;
	//the state of looking changes
	//each if v[i]=true means that if you start from here you will win
	cout<<(v[n]?"Azel":"Byssa")<<'\n';
    }
    return 0;
}

// 4 2 10 42 75862
