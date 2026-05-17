#include <bits/stdc++.h>
using namespace std;

bool check(pair<int, int> start, pair<int, int> dst, string_view wind,long long int n) {

    // the algorthim wil be gready
    // i know that i can't reach the dest i after doing
    // a full cycle i did not get closer to the dest
    auto begin = start;
    for (long long int j=0;j<min(n,(long long)wind.size());j++) {
	char i = wind[j];
        switch (wind[i % (wind.size())]) {
        case 'U': {
            if (start.second < dst.second) {
                start.second += 1;
                if (start.first < dst.first) {
                    start.first += 1;
                } else if (start.first > dst.first) {
                    start.first += 1;
                }
                // we can do nothing
            }
            // we have to counter the wind;

        }; break;
        case 'D': {
            if (start.second > dst.second) {
                start.second -= 1;
                if (start.first < dst.first) {
                    start.first += 1;
                } else if (start.first > dst.first) {
                    start.first -= 1;
                }
                // we can do nothing
            }
            // we have to counter the wind;

        }; break;
        case 'L': {
            if (start.first > dst.first) {
                start.first -= 1;
                if (start.second < dst.second) {
                    start.second += 1;
                } else if (start.second > dst.second) {
                    start.second -= 1;
                }
                // we can do nothing
            }
            // we have to counter the wind;

        }; break;
        case 'R': {
            if (start.first < dst.first) {
                start.first += 1;
                if (start.second < dst.second) {
                    start.second += 1;
                } else if (start.second > dst.second) {
                    start.second -= 1;
                }
                // we can do nothing
            }
            // we have to counter the wind;

        }; break;
        }
    }
    if(n<(long long)wind.size()){
	return start==dst;
    }
    //else i need the check if the diff is the diff between the ones i 
    if (begin.first != dst.first) {
        if (abs(begin.first - dst.first) > (start.first - dst.first)) {
	    int step_x=abs(start.first-dst.first);
	    int diff_x=abs(begin.first-dst.first);
	    return diff_x/step_x<=(n/(long long)wind.size());
	    
            if (begin.second != dst.second) {
                if (abs(begin.second - dst.second) >
                    (start.second - dst.second)) {
		    //we got closer
		    // i need to check if i can there fast enough
		    int step_y=abs(start.second-dst.second);
		    int diff_y=abs(begin.second-dst.second);
		    return diff_y/step_y<=(n/(long long)wind.size());
                }
                return false;
            }
            return false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pair<int, int> start;
    cin >> start.first >> start.second;
    pair<int, int> end;
    cin >> end.first >> end.second;
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long int l = 0;
    //this should be sufficent since it i can get there i will advance by two 
    //so thie max is 2*1e9
    long long int r = LONG_LONG_MAX;
    if(!check(start,end,s,LONG_LONG_MAX)){
	cout<<-1;
	return 0;
    }

    while (l < r) {
        auto mid = l + (r - l + 1) / 2;
	//i should infact never get an overflow
	if(check(start,end,s,mid)){
	    r=mid;
	}else{
	    l=mid+1;
	}
    }
    cout<<l;

    return 0;
}

// 0 0 4 6 3 UUU
