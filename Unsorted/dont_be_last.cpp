#include <bits/stdc++.h> 

using namespace std; 

int main() {
    ifstream in("notlast.in");
    int n;
    in>>n;
    unordered_map<string,int> cows= {{"Bessie",0}, {"Elsie",0}, {"Daisy",0}
	,{"Gertie",0}, {"Annabelle",0}, {"Maggie",0}, {"Henrietta",0}};
    for (int i=0;i<n;i++){
	string cow;
	int milk;
	in>>cow>>milk;
	cows[cow]+=milk;
    }
    vector<pair<int,string>> res;
    for (pair<string,int> i : cows){
	res.push_back({i.second,i.first});
    }
    sort(res.begin(),res.end());
    int min = res[0].first;
    int sec=-1;
    for (int i = 1;i!=res.size();i++){
	if (res[i].first!=min){
	    sec=i;
	    break;
	}
    }
    ofstream out("notlast.out");
    if (sec==-1){
	out<<"Tie\n";
    }else if(sec!=(res.size()-1) && res[sec].first == res[sec+1].first){
	out<<"Tie\n";
    }else{
	out<<res[sec].second<<'\n' ;
    }
}
