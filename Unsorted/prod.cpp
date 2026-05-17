#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	int a;
	for(int i=2;(i*i)<n;i++){
	    if(n%i==0){
		a=i;
		n/=i;
		break;
	    }
	}
	//a is the smallest possible number that divides a
	int b{-1};
	for(int i=2;(i*i)<n;i++){
	    if(i==a)continue;
	    if(n%i==0){
		b=i;
		n/=i;
		break;
	    }
	}
	if(b==-1 || b==n || a==n){
	    printf("NO\n");
	}else{
	    printf("YES\n%d %d %d\n",a,b,n);
	}

    }


    return 0;
}

// 5 64 32 97 2 12345
