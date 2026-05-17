#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("diamond.in"); 
    int n,k;
    in>>n>>k;
    vector<int>v(n);
    for(auto& i: v){
	in>>i;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
    }
    for(auto i: v){
	printf("%d ",i);
    }
}
