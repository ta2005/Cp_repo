#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("cbarn.in");
    int n;
    in>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++){
	in>>v[i];
    }
    int res=INT_MAX;
    for (int i=0;i<n;i++){
	int sum{};
	for (int j=0;j<n;j++){
	    if (j<i){
		sum+=(v[j]*(n-(i-j)));
	    }else if(j>i){
		sum+=(v[j]*(j-i));
	    }
	}
	res=min(res,sum);
    }
    ofstream out("cbarn.out");
    out<<res;
}
