#include <bits/stdc++.h> 
#include <utility>

using namespace std; 

int main() {
    ifstream in("crossroad.in");
    int n;
    in>>n;
    vector<int> cross(10,-1);
    int res{};
    for (int i=0;i<n;i++){
	int a,b;
	in>>a>>b;
	res+=(cross[--a]!=-1 && cross[a]!=b);
	cross[a]=b;
    }
    pair<int,int> p = {1,2};
    ofstream out("crossroad.out");
    out<<res;
}
// 8 3 1 3 0 6 0 2 1 4 1 3 0 4 0 3 1
