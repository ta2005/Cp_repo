#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> pref_xor_one(n + 1);
        vector<int> pref_xor(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        string s;
        cin >> s;
        for (int i = 0; i < (int)s.size(); i++) {
            pref_xor_one[i + 1] = pref_xor_one[i] ^ (v[i]*(s[i]-'0'));
            pref_xor[i + 1] = pref_xor[i] ^ (v[i]);
        }
        int one_xor{pref_xor_one[n]};
        int total_xor = {pref_xor[n]};
        int q;
        cin >> q;
        // well the obvious i can't process ever 1 command
        // neither every 2 command even with clever storage
        // second observation i don't need to process both 1 and 0
        // since the res of zero is just total_xor^1_xor
        for (int i = 0; i < q; i++) {
            int tp;
            cin >> tp;
            switch (tp) {
                case 2: {
                    int bit;
                    cin >> bit;
                    if (bit == 0) {
                        cout << (total_xor ^ one_xor) << ' ';
                    } else {
                        cout << one_xor << ' ';
                    }
                } break;
		case 1: {
		    int l,r;cin>>l>>r; 
		    // asm("int3");
		    // printf("pref_xor_one[r]
		    one_xor^=(pref_xor[r]^pref_xor[l-1]);
		} break;
            }
        }
	cout<<'\n';
    }
    return 0;
}

// 5 5 1 2 3 4 5 01000 7 2 0 2 1 1 2 4 2 0 2 1 1 1 3 2 1 6 12 12 14 14 5 5 001001 3 2 1 1 2 4 2 1 4 7 7 7 777 1111 3 2 0 1 2 3 2 0 2 1000000000 996179179 11 1 2 1 5 1 42 20 47 7 00011 5 1 3 4 1 1 1 1 3 4 1 2 4 2 0
