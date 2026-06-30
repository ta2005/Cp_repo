#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("cardgame.in");
    ofstream out("cardgame.out");
    ios::sync_with_stdio(false);
    in.tie(0);
    int n;
    in>>n;
    vector<int>a(n);
    vector<int>b(n);
    set<int>s;
    //the creation of the array could be moved to a function but move sematics and stuff ehhhhhhhhhhhhh
    for(int i=1;i<=2*n;i++){
	s.insert(i);
    }
    for(int i=0;i<n;i++){
	in>>a[i];
    }
    for(int i=0;i<n;i++){
	s.erase(a[i]);
    }
    int index{};
    for(auto i:s){
	b[index++]=i;
    }
    //in the first half will only look at the big side
    //at each postion the cow will try to win the round with the biggest value she can aquire
    int count{};
    vector<bool>used(n);
    for(int i=0;i<n/2;i++){
	for(int j=n/2;j<n;j++){
	    if(!used[j] && b[j]>a[i]){
		used[j]=true;
		count++;
		break;
	    }
	}
    }
    //at each postion the cow will try to win the round with the biggest value she can aquire
    for(int i=n/2;i<n;i++){
	for(int j=(n/2-1);j>=0;j--){
	    if(!used[j] && b[j]<a[i]){
		used[j]=true;
		count++;
		break;
	    }
	}
    }
    out<<count;
    return 0;
}
// 4 1 8 4 3
