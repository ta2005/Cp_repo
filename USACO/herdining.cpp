#include <bits/stdc++.h> 
#include <fstream>

using namespace std; 

int main() {
    ifstream in("herding.in");
    int n;
    in>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++){
	in>>v[i];
    }
    sort(v.begin(),v.end());

}
