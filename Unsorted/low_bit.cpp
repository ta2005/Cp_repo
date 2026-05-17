#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sum,limit;
    cin>>sum>>limit;
    vector<pair<int,int>>v(limit+1);
    for(int i=1;i<=limit;i++){
	v[i]={i&(~(i-1)),i};
    }
    sort(v.begin(),v.end(),std::greater<pair<int,int>>());
    //now we have a classic problem of subarray sum
    long long curr_sum{};
    vector<int>res;
    for(int i=0;i<limit;i++){
	if((curr_sum+v[i].first)<=sum){
	    curr_sum+=v[i].first;
	    res.push_back(v[i].second);
	}
    }
    if(curr_sum!=sum){
	cout<<-1;
	return 0;
    }
    cout<<res.size()<<'\n';
    for(auto i:res){
	cout<<i<<' ';
    }

    return 0;
}
