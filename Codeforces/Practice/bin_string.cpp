#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;
        string w(s.length(), '1');
        for (int i = 0; i < (int)s.length(); i++) {
            // the thing i know is that is
            // a s[i]='0' then the char before it
            // and after must be both zero
            if (s[i] == '0') {
                if (i >= x) {
                    w[i - x] = '0';
                }
                if (i + x < ((int)s.length())) {
                    w[i + x] = '0';
                }
            }
        }
        bool test = true;
        for (int i = 0; i < (int)s.length(); i++) {
            // the thing i know is that is
            // a s[i]='0' then the char before it
            // and after must be both zero
            if (s[i] == '1') {
		int count{};
                if (i >= x) {
		    count+=(w[i - x] != '0');
                }
                if (i + x  < ((int)s.length())) {
		   count+= (w[i + x] != '0');
                }
		if(count==0){
		    test=false;
		    break;
		}
            }
        }
        if (test) {
            cout << w << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}

// 3 101110 2 01 1 110 1
