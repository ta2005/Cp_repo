#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    //I try to exploit the fact n <= 1e6 
    //My task is to calulate the number of people such 
    //that the intersection in their time is bigger than d 
    //the intersection in time is the difference between
    //min(ti,tj)-max(si,sj)
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
	cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    set<int>s;
    long long res{};
    //i made the permuations but i don't know about the times
    for(int i=0;i<n;i++){
	if((v[i].second-v[i].first)<d)continue;
	int time=v[i].first+d;
	auto it=lower_bound(s.begin(),s.end(),time);
	//must find and effiecent way for 
	//sum for min(leave[i],leave[after])-time
	for(auto itb=it;itb!=s.end();itb++){
	    res+=(long long)min(v[i].second,*itb)-time+1;
	}
	s.insert(v[i].second);
    }
    cout<<res;



    return 0;
}
