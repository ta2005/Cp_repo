#include <bits/stdc++.h>
using namespace std;

//fun fact coping an int is better for the cash than copiing they references
//they are smallar and have spacial locality
//well java devs won't understand
bool check(vector<vector<int>>&v,int i,int j,int k,int n){
    bool c=true;//true is i appears before j
    for (int h=0;h<n;h++){
	if (v[0][h]==j+1){
	    c=false;
	    break;
	}else if (v[0][h]==i+1){
	    c=true;
	    break;
	}
    }
    for (int in=1;in<k;in++){
	bool ch = true;
	for (int h=0;h<n;h++){
	    if (v[in][h]==j+1){
		ch=false;
		break;
	    }else if (v[in][h]==i+1){
		ch=true;
		break;
	    }
	}
	if (ch!=c) return false;
    }

    return true;
}



int main() {
    ifstream in("gymnastics.in");
    int k,n;
    in>>k>>n;
    vector<vector<int>> v(k,vector<int>(n));
    for (int i=0;i<k;i++){
	for (int j=0;j<n;j++){
	    in>>v[i][j];
	}
    }
    //since n is small n i can brute force it 
    //i will iterate over all pairs and see whick one are consistantn
    int count{};
    for (int i=0;i<n;i++){
	for (int j=i+1;j<n;j++){
	    if (check(v,i,j,k,n)){
		count++;
		// cout<<i<<' '<<j<<endl;
	    }
	}
    }
    ofstream out("gymnastics.out");
    out<<count;
    return 0;
}
