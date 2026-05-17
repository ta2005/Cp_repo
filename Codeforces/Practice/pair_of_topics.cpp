#include <bits/stdc++.h> 

using namespace std; 

struct good{
    int t,s;
    bool operator<(const good& b){
	return (this->t-this->s)>(b.t-b.s);
    }
};

int main() {
    int n;
    cin>>n;
    vector<good>v(n);
    vector<int>d(n);
    for (int i=0;i<n;i++){
	cin>>v[i].t;
    }
    for (int i=0;i<n;i++){
	cin>>v[i].s;
	d[i]=v[i].t-v[i].s;
    }
    sort(d.begin(),d.end());
	//    for (auto i:v){
	// cout<<i.t<<' '<<i.s<<endl;
	//    }
	//    for (auto i:d){
	// cout<<i<<endl;
	//    }
    long long int count{};
    for (int i=n-1;i>0;i--){
	auto pos=upper_bound(d.begin(),d.end(),-d[i]);
	if (pos!=d.end() && (pos-d.begin()<i)){
	    count+=i-(pos-d.begin());
	}
    }
    cout<<count;
}

// 5 4 8 2 6 2 4 5 4 1 3
//4 1 3 2 4 1 3 2 4
