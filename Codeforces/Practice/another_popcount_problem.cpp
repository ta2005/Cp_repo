#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        // I will find the nbr closet to n with the most nbr of ones
        int big{};
	int pop{};
        for (int i = 1; i < 25; i++) {
            if (((1 << i) - 1) <= n) {
		pop=i;
                big = (1 << i) - 1;
            }
        }
        // cout << pop << ' ' << big << '\n';
	long long acc{};
	long long res{};
	while((acc+big)<n){
	    acc+=big;
	    res+=pop;
	}
	res+=(n-acc);
	cout<<res<<'\n';
    }
    return 0;
}
