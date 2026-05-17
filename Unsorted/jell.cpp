#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    vector<long long> v(10);
    for (int i = 0; i < q; i++) {
	int quer;
	cin >> quer;
	switch (quer) {
	    case 1: 
		{
		    int k;
		    cin>>k;
		    for (int j=0;j<k;j++){
			int a;
			cin>>a;
			v[a-1]++;
		    }
		} break;
	    case 2:
		{
		    int pos;
		    cin>>pos;
		    int sum{};
		    int j{};
		    while ((sum+v[j])<pos){
			sum+=v[j++];
		    }
		    cout<<j+1<<'\n';
		}
	}
    }
}

// 5 1 5 3 7 2 7 5 2 3 1 3 1 10 4 2 6 2 1
