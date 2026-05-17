#include <bits/stdc++.h>
using namespace std;

int log(int&n,int p){
    int res{};
    while(n%p==0){
	res++;
	n/=p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    int count{};
    count+=abs(log(a,2)-log(b,2));
    count+=abs(log(a,3)-log(b,3));
    count+=abs(log(a,5)-log(b,5));
    if(a!=b) cout<<-1;
    else cout<<count;


    return 0;
}
