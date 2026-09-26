#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int lk{};
    for (auto i : s) {
        if (i == '4' || i == '7') {
            lk++;
        }
    }
    if (lk == 4 || lk==7){
	cout<<"YES\n";
    }else{
	cout<<"NO\n";
    }
}
