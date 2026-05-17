#include <bits/stdc++.h> 

using namespace std; 

struct sensor{
    string s;
    int a,b;
};

int main() {
    ifstream in("traffic.in");
    ofstream out("traffic.out");
    pair<int,int> state{0,0};
    bool test=true;
    int start=0;
    int n;
    in>>n;
    vector<sensor> v(n);
    for (int i=0;i<n;i++){
	in>>v[i].s>>v[i].a>>v[i].b;
	if (test && v[i].s=="none"){
	    state.first=v[i].a;
	    state.second=v[i].b;
	    test=false;
	    start=i;
	}
    }
    for (int i=start+1;i<n;i++){
	if (v[i].s=="on"){
	    state.first+=v[i].a;
	    state.second+=v[i].b;
	}else if (v[i].s=="off"){
	    state.second-=v[i].a;
	    state.first-=v[i].b;
	    state.first=max(state.first,0);
	}else{
	    state.first=max(state.first,v[i].a);
	    state.second=min(state.second,v[i].b);
	}
    }
    pair<int,int> state1{0,0};
    for (int i=n-1;i>=0;i--){
	if (v[i].s=="none"){
	    state1.first=v[i].a;
	    state1.second=v[i].b;
	    start=i;
	    break;
	}
    }
    for (int i=start-1;i>=0;i--){
	if (v[i].s=="off"){
	    state1.first+=v[i].a;
	    state1.second+=v[i].b;
	}else if (v[i].s=="on"){
	    state1.second-=v[i].a;
	    state1.first-=v[i].b;
	    state1.first=max(state1.first,0);
	}else{
	    state1.first=max(state1.first,v[i].a);
	    state1.second=min(state1.second,v[i].b);
	}
    }
    out<<state1.first<<' '<<state1.second<<'\n';
    out<<state.first<<' '<<state.second<<'\n';
}
// 4 on 1 1 none 10 14 none 11 15 off 2 3
