#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<int, 10> count{};
    int n;cin>>n;
    string s;
    cin >> s;
    for (char c : s) {
        for (int i = 2; i <= (c - '0'); i++) {
            switch (i) {
                case 4:
                    count[2] += 2;
                    break;
                case 8:
                    count[2] += 3;
                    break;
                case 6:
                    count[2] += 1;
                    count[3] += 1;
                    break;
                case 9:
                    count[3] += 2;
                    break;
                default:
                    count[i]++;
            }
        }
    }
    string res;
    for (int i = 9; i >= 0; i--) {
        if (count[i] == 0)
            continue;
        int c = count[i];
        count[i] = 0;
	for(int a=0;a<c;a++){
	    res += i + '0';
	}
        for (int j = i - 1; j >= 0; j--) {
            switch (j) {
                case 4:
                    count[2] -= 2*c;
                    break;
                case 8:
                    count[2] -= 3*c;
                    break;
                case 6:
                    count[2] -= 1*c;
                    count[3] -= 1*c;
                    break;
                case 9:
                    count[3] -= 2*c;
                    break;
                default:
                    count[j]-=c;
            }
        }
    }
    cout<<res;
    //    for(auto i:count){
    // cout<<i<<' ';
    //    }
    return 0;
}
