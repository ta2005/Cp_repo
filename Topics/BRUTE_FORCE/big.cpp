#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("cowsignal.in");
    ofstream out("cowsignal.out");
    int n,m,k;
    in>>n>>m>>k;
    vector<string> v(n);
    for (int i=0;i<n;i++){
	in>>v[i];
    }
    for (int i=0;i<n;i++){
	vector<char> res(m*k);
	for(int j=0 ;j<m;j++){
	    char p = v[i][j];
	    for(int c=0;c<k;c++){
		res[j*k+c]=p;
	    }
	}
	for(int c=0 ;c<k;c++){
	    for (auto b:res){
		out<<b;
	    }
	    out<<endl;
	}
    }
}
// 5 4 2 XXX. X..X XXX. X..X XXX.
