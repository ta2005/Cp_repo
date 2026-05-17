#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	vector<int>b(n);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	for(int i=0;i<n;i++){
	    cin>>b[i];
	}
	set<int>s;
	for(int i=n-1;i>=(n-k);i--){
	    s.insert(a[i]); 
	}
	vector<int>miss;
	set<int>org=s;
	for(int i=n-1;i>=(n-k);i--){
	    if(b[i]==-1){
		miss.push_back(i);
	    }else{
		s.erase(b[i]);
	    }
	}
	for(int i=0;i<(n-k);i++){
	    s.erase(b[i]);
	}
	bool test=true;
	if(s.size()==miss.size()){
	    //i will add them in the same order
	    vector<int>to_add;
	    for(int i=n-1;i>=(n-k);i--){
		if(s.count(a[i])==1){
		    to_add.push_back(a[i]);
		}
	    }
	    for(int i=0;i<(int)s.size();i++){
		b[miss[i]]=to_add[i];
	    }
	    //i just like the name s
	    s.swap(org);
	    for(int i=n-1;i>k;i--){
		int from_a=a[i];
		int from_b=b[i];
		int add_a=a[i-k];
		int add_b=b[i-k];
		if(from_a!=from_b){
		    test=false;
		    break;
		}
		if(add_b==-1){
		    b[i-k]=add_a;
		    add_b=b[i-k];
		}else if(add_b!=add_a){
		    test=false;
		    break;
		}else{
		    s.erase(from_a);
		    s.insert(add_a);
		}
	    }
	}else{
	    test=false;
	}
	if(test){
	    cout<<"YES\n";
	}else{
	    cout<<"NO\n";
	}
    }
    return 0;
}

// 4 5 5 1 2 3 4 5 3 1 5 2 4 5 4 4 1 2 5 3 2 -1 -1 -1 -1 6 4 1 2 4 3 5 6 -1 -1 3 -1 -1 -1 6 4 1 2 4 3 5 6 -1 -1 3 3 -1 -1
