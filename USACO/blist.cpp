#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("blist.in");
    int n;
    in>>n;
    vector<int> cow(1000);
    for (int i=0;i<n;i++){
	int s,t,b;
	in>>s>>t>>b;
	cow[s-1]=b;
	cow[t-1]=-b;
    } 
    int res{};
    int count{};
    for (int i=0;i<1000;i++){
	count+=cow[i];
	res=max(count,res);
    }
    ofstream out("blist.out");
    out<<res;
} 
