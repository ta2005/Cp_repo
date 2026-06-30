#include <bits/stdc++.h>
using namespace std;

// int calc(vector<int>&v,int q,int x,int m){
//     int l = 0, r = (q-q%x);
//     while (l < r) {
// 	int mid = l + (r - l) / 2;
// 	if (mid==0) {
// 	    l = mid + 1;
// 	} else {
// 	    r = mid;
// 	}
//     } 
//     return 0;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q,x;
    cin>>q>>x;
    set<int>s;
    vector<int>v(x);
    for(int i=0;i<x;i++){
	v[i]=i;
    }
    for(int i=0;i<q+1;i++){
	s.insert(i);
    }
    for(int i=0;i<q;i++){
	int a;
	cin>>a;
	int b=a%x;
	//how to binary search for this thing 
	// for(int i:s){
	//     if(i%x==b){
	// 	s.erase(i);
	// 	break;
	//     }
	// }
	if(v[b]<q){
	    s.erase(v[b]);
	    v[b]+=x;
	}
	//i will search in the set for the first integer such that it%x=b
	// int add=calc(w,q,x,b);
	// s.erase(add);
	cout<<*s.begin()<<'\n';
    }
    return 0;
}

// 7 3 0 1 2 2 0 0 10
