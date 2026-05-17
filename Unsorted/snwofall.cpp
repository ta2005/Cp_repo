#include <bits/stdc++.h>
using namespace std;

bool cmp(const int& a,const int& b){
    if(a%6==0){
	return true;
    }
    if(b%6==0){
	return false;
    }
    if(a%3==0){
	return true;
    }
    if(b%3==0){
	return false;
    }
    if(a%2==0){
	return true;
    }
    if(b%2==0){
	return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i=0;i<n;i++){
	    cout<<v[i]<<" ";
	}
	cout<<'\n';
    }
    return 0;
}

// 5 6 12 7 9 4 18 5 4 3 6 2 8 7 1 10 15 20 3 6 9 5 11 14 21 2 5 3 6 6 6
