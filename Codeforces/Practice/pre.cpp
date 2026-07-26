#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	array<int,4>arr{0};
	array<int,4>arr1{0};
	int state=0;
	int state1=0;
	for(int i=0;i<n;i++){
	    arr[v[i]]++;
	    arr1[v[i]]++;
	    if(state==0){
		if(arr[1]>(arr[2]+arr[3])){
		    state=1;
		    arr[1]=arr[2]=arr[3]=0;
		}
	    }else if(state==1){
		if(i!=n-1 && (arr[1]+arr[2])>=arr[3]){
		    state=2;
		}
	    }
	    if(state1==0){
		if(arr1[1]==arr1[2]+arr1[3]){
		    state1=1;
		    arr1[1]=arr1[2]=arr1[3]=0;
		}
	    }else{
		if(i!=n-1 && (arr1[1]+arr1[2])>=arr1[3]){
		    state1=2;
		}
	    }
	}
	if (state==2 || state1==2){
	    cout<<"YES\n"; 
	}else{
	    cout<<"NO\n";
	}
    }

    return 0;
}

// 10 8 2 1 1 3 3 1 2 3 7 2 1 3 3 3 2 3 4 1 3 3 2 6 2 2 2 1 1 1 8 3 2 1 2 1 1 2 3 3 2 1 2 3 1 2 3 5 1 3 3 1 1 5 1 1 3 3 1 3 1 3 1
