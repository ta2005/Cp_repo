#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if ((b/m)<a){
	int res=(n/m)*b;
	int c=n%m;
	res+=min(b,c*a);
	cout<<res<<'\n';
    }else{
	cout<<a*n<<'\n';
    }
}

// 6 2 1 2
// 5 2 2 3
