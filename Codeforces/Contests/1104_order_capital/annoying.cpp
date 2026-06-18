#include <bits/stdc++.h>
using namespace std;

int main() {
    // ok ok slow down you have 3 hours so
    // everythin is fine
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
	vector<int>used(n);
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n; j++) {
                if (!used[j] && a[j] <= b[i]) {
		    used[j]=true;
                    a[j] = b[i];
		    break;
                }
            }
        }
	int count{};
	for(int i=0;i<(n-1);i++){
	    int j=i+1;
	    while(j>=1 && a[j]<a[j-1]){
		swap(a[j],a[j-1]);
		j--;
		count++;
	    }
	}
	bool test=true;
	for(int i=0;i<n;i++){
	    if(a[i]!=b[i]){
		cout<<-1<<'\n';
		test=false;
		break;
	    }
	}
	if(test) cout<<count<<'\n';
    }

    // the min nbr of swaps is bascially running insertion sort and couting the
    // nbr of iteration

    return 0;
}

// 10 3 1 2 2 1 3 5 3 2 2 1 1 2 3 2 5 1 2 4 6 6 5 4 3 2 1 1 2 3 4 5 6 7 4 7 1 6 2 5 3 1 2 3 4 5 6 7 2 2 1 2 3 4 3 2 2 1 1 2 3 4 4 4 3 2 1 1 3 4 5 5 1 5 4 3 2 2 3 4 5 6 5 10 3 8 6 9 3 6 8 9 10
//1 3 2 2 1 1 2 3
//1 4 3 2 2 1 1 2 3 4
