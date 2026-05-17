#include <bits/stdc++.h>
using namespace std;

//i will run the simulation 
//first going from the least cow in the y axis i will use the cows that travel 
//east 
//keep an array of the state of all the cows
//

//best practices tell you to put bigger fields first 
//but not my problem now 
struct cow{
    char dir;
    int x;
    int y;
    int id;
    bool operator < (const cow& other)const{
	if (this->dir!=other.dir){
	    return this->dir<other.dir;
	}else if(this->dir=='E'){
	    return this->y<other.y;
	}else{
	    return this->x<other.x;
	}

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<cow> v(n);
    for (int i=0;i<n;i++){
	cin>>v[i].dir;
	cin>>v[i].x;
	cin>>v[i].y;
	v[i].id=i;
    }
    sort(v.begin(),v.end());
    vector<int> state(n,-1);
    for (int i=0;i<n;i++){
	if (v[i].dir=='N') break;
	for (int j=0;j<n;j++){
	    if (v[j].dir=='E' || state[v[j].id]!=-1) continue;
	    int dis = v[i].y-v[j].y;
	    int dis2 = (v[j].x-v[i].x);

	    if (dis2>0 && dis>dis2){
		state[v[j].id]=dis;
	    }else if (dis>0 && dis<dis2){
		state[v[i].id]=dis2;
		break;
	    }
	}

    }
    for (auto i : state){
	if (i==-1){
	    cout<<"Infinity\n";
	}else{
	    cout<<i<<'\n';
	}
    }
    return 0;
}
// 6 E 3 5 N 5 3 E 4 6 E 10 4 N 11 2 N 8 1
