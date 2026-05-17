#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    //no traversal is needed
    //v holds the nbr of neighborus
    vector<int> v(n);
    for (int i=0;i<m;i++){
	int a,b;
	cin>>a>>b;
	v[--a]++;
	v[--b]++;
    }
    // theree differenct top i will simplyy run a loop for each 
    // topology
    bool ring=true;
    for (int i=0;i<n && ring;i++){
	if (v[i]!=2) ring=false;
    }
    if (ring){
	cout<<"ring topology";
	return 0 ;
    }
    bool bus=true;
    int nbr{};
    for (int i=0;i<n && bus;i++){
	if (v[i]>2) bus = false;
	if (v[i] == 1){
	    nbr++;
	    if (nbr>2){
		bus=false;
	    }
	}
    }
    if (bus){
	cout<<"bus topology";
	return 0 ;
    }
    bool star=true;
    nbr=0;
    for (int i=0;i<n && star;i++){
	if (v[i] == n-1){
	    nbr++;
	    if (nbr>1){
		star=false;
	    }
	}else if(v[i]!=1){
	    star=false;
	}
    }
    if (star){
	cout<<"star topology";
	return 0 ;
    }
    cout<<"unknown topology";
    return 0;
}
