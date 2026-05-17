#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	int i=0;
	int j=0;
	vector<int>neg(n);
	vector<int>pos(n);
	long long int sn{};
	long long int sp{};
	for (int k=0;k<n;k++){
	    int nbr;
	    cin>>nbr;
	    if (nbr<0){
		sn+=nbr;
		neg[j++]=nbr;
	    }else{
		sp+=nbr;
		pos[i++]=nbr;
	    }
	}
	sort(pos.begin(),pos.begin()+i,std::greater<int>());
	sort(neg.begin(),neg.begin()+j,std::greater<int>());
	long long res{};
	if (i<j){
	    res=sp;
	    for (int k=0;k<i;k++){
		res+=neg[k];
	    }
	} else if (j<i){
	    res=sn;
	    for (int k=0;k<j;k++){
		res+=pos[k];
	    }
	}else{
	    res=sp+sn;
	}
	cout<<res<<'\n';
    }
    return 0;
}
// 4 5 1 2 3 -1 -2 4 -1 -2 -1 -3 10 -2 8 3 8 -4 -15 5 -2 -3 1 6 1 -10000 1 -10000 1 -10000
// 4 5 1 2 3 -1 -2 4 -1 -2 -1 -3 10 -2 8 3 8 -4 -15 5 -2 -3 1 6 1 -1000000000 1 -1000000000 1 -1000000000
// 1 10 -2 8 3 8 -4 -15 5 -2 -3 1
