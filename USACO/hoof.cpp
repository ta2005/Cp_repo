#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("hps.in");
    int n;
    in>>n;
    vector<int> h(n+1);
    vector<int> p(n+1);
    vector<int> s(n+1);
    for (int i=0;i<n;i++){
	char a;
	in>>a;
	h[i+1]=h[i];
	p[i+1]=p[i];
	s[i+1]=s[i];
	switch (a){
	    case 'P' : p[i+1]++;break;
	    case 'H' : h[i+1]++;break;
	    case 'S' : s[i+1]++;break;
	}
    }
    //based on the current index what is the max that she can make
    int res=0;
    for (int i=1;i<=n;i++){
	int sum=max({h[i-1],p[i-1],s[i-1]})+ max({h[n]-h[i-1],p[n]-p[i-1],s[n]-s[i-1]});
	res=max(sum,res);
    }
    ofstream out("hps.out");
    out<<res;
}
