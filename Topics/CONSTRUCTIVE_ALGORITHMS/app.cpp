#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> res(n);
    for (int i=0;i<n;i++){
	cin>>res[i];
    }
    vector<int> app(m);
    for (int i=0;i<m;i++){
	cin>>app[i];
    }
    sort(app.begin(),app.end());
    sort(res.begin(),res.end());
    int i=0;
    int j=0;
    int count{};
    while (i<n && j<m){
	if (((app[j]-k)<=res[i]) && (res[i]<=(app[j]+k))){
	    count++;
	    i++;
	    j++;
	}
	while(i<n && res[i]<(app[j]-k)){
	    i++;
	}
	while(j<m && (app[j]+k)<(res[i])){
	    j++;
	}
    }
    cout<<count;
}
// 4 3 5 60 45 80 60 30 60 75
