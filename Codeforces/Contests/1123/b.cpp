#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        // i can simply brut force it
        // I will have a greedy algo
        // that trie and make each pref a big as apoo
        // this one tells me whether I have used
        // an ele
        vector<bool> used(n);
        vector<int> res(n);
        vector<int> count(101);
        res[0] = v[n - 1];
        used[n - 1] = true;
        count[v[n - 1]]++;
        for (int i = 1; i < n; i++) {
            // i will alway try and add the next biggest item
            int choice=-1;
	    int mod=-1;
            for (int j = 0; j < n; j++) {
		// if i choose this one what will 
		// the md become
                if (used[j])
                    continue;
                count[v[j]]++;
                int index = 0;
                for (int k = 1; k < 101; k++) {
                    if (count[k] > count[index]) {
			index=k;
                    }else if(count[k]==count[index] && k>index){
			index=k;
		    }
                }
		count[v[j]]--;
		int md=index;
		// this is the mod after choosing it
		if(choice==-1){
		    choice=j;
		    mod=md;
		}else if(md>mod){
		    choice=j;
		    mod=md;
		}
            }
	    // cout<<choice<<'\n';
	    res[i]=v[choice];
	    used[choice]=true;
	    count[v[choice]]++;
        }

	for(auto i:res){
	    cout<<i<<' ';
	}
	cout<<'\n';
    }
}

// 7 3 2 3 2 6 4 4 2 1 3 1 5 1 3 2 4 2 4 1 1 1 2 7 1 2 3 4 5 6 7 8 1 1 4 2 3 3 3 2 8 4 3 3 3 2 1 4 1
