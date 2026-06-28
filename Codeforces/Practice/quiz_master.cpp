#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        // a sol exitst if all the divisors
        // of ai cover 1 to m
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<long long> freq(m + 1);
        // I think i will need to ignore the ai
        // and try to find for each i from 1 to m
        // i want to minimize the diff between the max
        // and min
        // here is what i will do i will have two pointers
        // from each end of the array
        // and see if i can remove each end of it
        // i am unable to remove and item it
        // is the only multiple of and nbr from 1 to m
        // the nbr of multiple of a nbr i in the range 1 to n
        // is m/i
        // in the third exmaple
        // why were we able to remove 3??
        // becaue 6 is a mutiple of 3
        // so it has more dvisors than 3
        // and remving and element from the other end ??
        // why could't we remove 7 becuase it is teh only ele
        // that covers 7
        // how can i check quickly for these???
        // first think we could move away from looking at divisors
        int l = 0;
        int r = 0;
        int covered_count = 0;
        int res = INT_MAX;
        while (r < n) {
            while (r < n && covered_count != m) {
                // I have no idea how to get the divisors
                // with optimal time
                for (int i = 1; i <= m && i * i <= v[r]; i++) {
                    if (v[r] % i == 0) {
                        // here i update
                        // the covered_count
                        if (freq[i] == 0) {
                            covered_count++;
                        }
                        freq[i]++;
                        if (v[r] / i <= m && v[r] / i != i) {
                            if (freq[v[r] / i] == 0) {
                                covered_count++;
                            }
                            freq[v[r] / i]++;
                        }
                    }
                }
                r++;
            }
            while (l<n && covered_count == m) {
                res = min(res, v[r-1] - v[l]);

                for (int i = 1; i <= m && i * i <= v[l]; i++) {
                    if (v[l] % i == 0) {
                        // here i update
                        // the covered_count
                        if (freq[i] == 1) {
                            covered_count--;
                        }
                        freq[i]--;
                        if (v[l] / i <= m && v[l] / i != i) {
                            if (freq[v[l] / i] == 1) {
                                covered_count--;
                            }
                            freq[v[l] / i]--;
                        }
                    }
                }
		l++;
            }
        }
	cout<<(res==INT_MAX?-1:res)<<'\n';
    }
    return 0;
}

// 3 2 4 3 7 4 2 3 7 2 9 5 7 6 4 3 5 7
