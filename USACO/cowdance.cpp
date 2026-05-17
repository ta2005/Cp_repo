#include <bits/stdc++.h>
using namespace std;

bool dance(vector<int> &v, int k, int t) 
{
    // calculate the time needed for the cows
    int n = v.size();
    vector<int> tmp(v.begin(), v.begin() + k);
    int time{};
    for (int i = k; i < n; i++) {
	auto var = min_element(tmp.begin(), tmp.end());
	*var += v[i];
    }
    return *max_element(tmp.begin(), tmp.end())<=t;
}

int main() 
{
    ifstream in("cowdance.in");
    int n, t;
    in >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
	in >> v[i];
    }
    // i will binary search for the value from 1 to  n and
    // find the greatest value that allows the cows to dance
    int lo = 1;
    int hi = n;
    while (lo < hi) {
	int mid = (lo + hi) / 2;
	if (dance(v, mid, t)) {
	    hi = mid;
	} else {
	    lo = mid + 1;
	}
    }
    ofstream out("cowdance.out");
    out << lo;
    return 0;
}
