//easy first try
//yeah time to have 1400 become my new baseline
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    //i can do bs
    //but let us say the time limit was 1e8
    //we visit each entrance at each will become 
    //empty at most v[i]-n*i
    //we can calc on which round the queue will be empty
    vector<int>time(n);
    for (int i=0; i<n; i++) {
	cin>>v[i];
	//this time repsents on which round v[i] will reach zero
	//i am interest in v[i]-i
	if(v[i]==0 || v[i]<i)continue;;
	time[i]=((v[i]-i)/n);
	if((v[i]-i)%n!=0){
	    time[i]++;
	}
    }
    int min=0;
    for(int i=0;i<n;i++){
	if(time[i]<time[min]){
	    min=i;
	}
	// cout<<time[i]<<' ';
    }
    cout<<min+1;

    return 0;
}
