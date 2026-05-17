#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("div7.in");
    int n;
    in>>n;
    unordered_map<int,int> pref;
    pref[0]=0;
    int res{};
    long long int sum{};
    for (int i=0;i<n;i++){
	int a;
	in>>a;
	sum+=a;
	if (pref.find(sum%7)!=pref.end()){
	    res=max(res,i-pref[sum%7]);
	}else{
	    pref[sum%7]=i;
	}
    }
    ofstream out("div7.out");
    out<<res;
}
