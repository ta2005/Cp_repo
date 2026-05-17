#include <bits/stdc++.h> 

using namespace std; 

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    vector<int>v(26);
    for (auto c:s){
	v[c-'a']++;
    }
    vector<int> w=v;
    sort(v.begin(),v.end(),std::greater<int>());
    for (int i = 1;i<26;i++){
	if (v[i]==0) break;
	if (v[i]!=v[i-1]){
	    cout<<-1;
	    return 0;
	}
    }
    if ((v[0]%k)!=0){
	cout<<-1;
	return 0;
    }
    vector<char>res(s.size());
    int j=0;
    int count=v[0];
    for (int k=0;k<count;k++){
	for (int i=0;i<26;i++){
	    if (w[i]!=0){
		res[j++]=(i+'a');
	    }
	}
    }
    for (auto c:res){
	cout<<c;
    }
}
// 2 aazz
