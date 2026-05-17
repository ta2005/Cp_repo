#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n;
    cin>>n;
    unordered_map<int,int> v;
    vector<int> arr(n);
    long long int count{};
    for (int i=0;i<n;i++){
	int a;
	cin>>a;
	v[a]++;
    }
    for (int i=0;i<n;i++){
	cin>>arr[i];
    }
    for (int i=0;i<n;i++){
	int a;
	cin>>a;
	count+=v[arr[a-1]];
    }
    cout<<count;
}

// 3 1 2 2 3 1 2 2 3 2
// 4 1 1 1 1 1 1 1 1 1 2 3 4
