#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    //is there a better of input ? i will read a sol after finishing 
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    vector<int> sorted_arr=v;
    sort(sorted_arr.begin(),sorted_arr.end());
    int pos=-1;
    for (int i=0;i<n;i++){
	if (v[i]!=sorted_arr[i]){
	    pos=i;
	    break;
	}
    }
    if (pos!=-1){
	int it=lower_bound(sorted_arr.begin(),sorted_arr.end(),v[pos])-sorted_arr.begin();
	int start=min(pos,it);
	int end=max(pos,it);
	reverse(sorted_arr.begin()+start,sorted_arr.begin()+end+1);
	if (sorted_arr==v){
	    cout<<"yes\n";
	    cout<<start+1<<' '<<end+1<<'\n';
	}else{
	    cout<<"no\n";
	}

    }else{
	cout<<"yes\n";
	cout<<1<<' '<<1<<'\n';
    }
    return 0;
}
// 4 2 1 3 4
