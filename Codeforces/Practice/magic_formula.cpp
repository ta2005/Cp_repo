#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int>v(n);
    long long acc{};
    for(int i=0;i<n;i++){
	cin>>v[i];
	acc^=v[i];
    }
    //Tom is a genuis : the primegean
    vector<int>diff_arr(n+1);
    for(int i=1;i<=n;i++){
	//i is the length of the seq 
	//it start from 1 and ends at 0
	int repeat = n /i;
	int rest = n%i;
	// printf("the length is %d and it repeats %d\n",rest,repeat);
	// i will not handle the odd even here but when i crete the prefix 
	diff_arr[0]+=repeat;
	diff_arr[i-1]-=repeat;
	diff_arr[0]+=rest!=0;
	diff_arr[rest]-=rest!=0;
    }
    vector<int>pref(n+1);
    for(int i=0;i<n;i++){
	pref[i+1]=pref[i]+diff_arr[i];
    }
    for(int i=1;i<=n;i++){
	// cout<<i<<' ';
	if ((pref[i]%2)==1){
	    acc^=i;
	}
    }
    cout<<acc<<'\n';
    return 0;
}
