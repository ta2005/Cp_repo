#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,m;
    cin>>a>>m;
    //a%m=a%m%m
    int acc{a};
    for(int i=0;i<10;i++){
	printf("on day %d we have %d\n",i,acc);
	acc+=acc%m;
    }

    return 0;
}
