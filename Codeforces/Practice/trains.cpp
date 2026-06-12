#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long  a,b;cin>>a>>b;
    long long ppcm = lcm(a,b);
    long long  count_a = ppcm/a;
    long long  count_b = ppcm/b;
    if(a<b){
	count_a--;
    }else{
	count_b--;
    }
    if(count_a<count_b){
	cout<<"Masha";
    }else if(count_b<count_a){
	cout<<"Dasha";
    }else{
	cout<<"Equal";
    }

    return 0;
}
