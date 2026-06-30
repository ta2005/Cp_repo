#include <bits/stdc++.h>
using namespace std;

enum cow{
    bessie,elsie,mildred
};


struct meas{
    int d;
    cow c;
    int q;
    bool operator < (const meas& other) const{
	return this->d<other.d;
    }

};

int main() {
    ifstream in("measurement.in"); 
    int n; 
    in>>n;
    vector<meas> v(n);
    for (int i=0;i<n;i++){
	in>>v[i].d;
	string s;
	in>>s;
	if (s=="Bessie"){
	    v[i].c=bessie;
	} else if (s=="Elsie"){
	    v[i].c=elsie;
	} else{
	    v[i].c=mildred;
	}
	in>>v[i].q;
    }
    sort(v.begin(),v.end());
    int count{};
    vector<int> arr = {7,7,7};
    //now all i need to do is measure the change in cow 
    vector<bool> has = {true,true,true};
    vector<bool> prev = {true,true,true};
    for (int i=0;i<n;i++){
	arr[v[i].c]+=v[i].q;
	int m = *max_element(arr.begin(),arr.end());
	for (int j=0;j<3;j++){
	    has[j]=arr[j]==m;		 
	}
	count+=!(prev==has);
	prev = has;
    }
    ofstream out("measurement.out");
    out<<count;
    return 0;
}
