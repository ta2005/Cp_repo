#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r_b{};
    int r_s{};
    int r_c{};
    int n_b{};
    int n_s{};
    int n_c{};
    int p_b{};
    int p_s{};
    int p_c{};
    int r{};
    string s;
    cin>>s;
    cin>>n_b>>n_s>>n_c;
    cin>>p_b>>p_s>>p_c;
    for(int i=0;i<(int)s.size();i++){
	if(s[i]=='B'){
	    r_b++;
	}else if (s[i]=='S'){
	    r_s++;
	}else{
	    r_c++;
	}
    }
    
    return 0;
}
