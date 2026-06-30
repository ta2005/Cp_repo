#include <bits/stdc++.h>
using namespace std;

vector<int>s;
vector<int>id;
//these are the users in each group;
vector<int>adj[500005];
int n,m;

void add(int user,int gid){
    if(id[user]!=gid){

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    //this is the size the size of the group that user belongs to 
    for(int i=0;i<n+1;i++){
	s.push_back(1);
    }
    //i will asuume each user belongs to his own group
    //this is the id of the group that user belongs to 
    for(int i=0;i<n+1;i++){
	id.push_back(i);
    }
    //i will have at most m ids
    for(int i=0;i<m;i++){
	int user;
	cin>>user;
	//add user to group i
	add(user,i);
    }

    return 0;
}
