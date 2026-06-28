#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    vector<int>diag(n);
    int sum{};
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cin>>v[i][j];
	}
    }
    for(int i=0;i<n;i++){
	sum+=v[i][i];
	diag[i]=v[i][i];
    }
    sum%=2;
    int q;cin>>q;
    // the product can either be one or zero 
    // it is zero if the nbr of ones is even
    // the nbr of queries is 1e6 so 
    // for each type of query i must do and O(1) 
    // operation
    // i will consider two types of operatoins:
    // getting the sum
    // flipping row 
    //	ok so doing examples on 2*2 and 3*3 
    //	reveals smth 
    //	a*2 = a mod 2
    //	and 2ab = 0 mod 2
    // the sum is only the sum of the diagonals 
    while(q--){
	int query_type;
	cin>>query_type;
	switch (query_type){
	    case 1:
	    case 2:
		{
		    int pos;
		    cin>>pos;
		    pos--;
		    sum+=(diag[pos]==1?-1:1);
		    diag[pos]=diag[pos]==1?0:1;
		    sum=(sum+2)%2;
		};break;
	    case 3:cout<<sum;
	}
    }

    return 0;
}

// 3 1 1 1 0 1 1 1 0 0 12 3 2 3 3 2 2 2 2 1 3 3 3 1 2 2 1 1 1 3
// 1 1 9 1 1 3 1 1 1 1 3 1 1 3 1 1 3
