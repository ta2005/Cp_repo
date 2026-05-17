#include <bits/stdc++.h> 

using namespace std; 

struct len{
    int start,end;
    bool operator<(const len&b){
	return (this->end-this->start)>(b.end-b.start);
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
	int n,k,x;
	cin>>n>>k>>x;
	vector<len> v(n-1);
	vector<int> p(n);
	for (int i=0;i<n;i++){
	    cin>>p[i];
	}
	sort(p.begin(),p.end());
	for (int i=0;i<n-1;i++){
	    v[i]={p[i],p[i+1]};
	}
	sort(v.begin(),v.end());
	int max=(v[0].start-v[0].end)/2;
	int s=p[0];
	int e=(x-p[n-1]);
	vector<int>res;
	while((s>max)&&(e>max)&&(k>0)){
	    k-=2;
	}
    }
}

// 10 4 1 4 1 0 2 4 5 5 4 0 1 2 3 4 2 1 4 4 0 3 4 6 2 4 3 3 2 12 6 12 0 4 3 12 8 12 0 4 1 1 1000000000 0 1 1 1000000000 1000000000 3 4 9 8 7 9 3 4 9 2 0 1
// 1 4 1 4 1 0 2 4 
