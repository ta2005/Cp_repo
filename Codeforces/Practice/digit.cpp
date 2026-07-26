#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
	// I must delete all 4
	// I must delete any three that come after a 2 
	// I must delete all 1 that appear before 2
	bool two=false;
	string s;cin>>s;
	int res{};
	int acc_1{};
	int acc_3{};
	for(auto i:s){
	    switch (i){
		case '4':res++;break;
		case '2':two=true;break;
		case '1' : acc_1+=!two;break;
		case '3' : acc_3+=!two;break;
	    }
	    if(two){
		res+=acc_1+acc_3;
	    }
	}
	cout<<res<<'\n';
    }
    return 0;
}
// 5 4 13 3244123 24424224242 4132423432241231
// 12 32 44
