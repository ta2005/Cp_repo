#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int n;
    cin>>n;
    vector<long long int>a(n);
    vector<long long int>b(n);
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    //ok so now multiplying the biggest with the biggest with the biggest is stupid
    for(int i=0;i<n;i++){
	cin>>b[i];
    }
    //so i tested my sum for and it is correct
    // long long res{};
    //since i can't move the ai i wil simply change them in place
    for(long long int k=0;k<n;k++){
	a[k]*=(k+1)*(n-k);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<long long int>());
    long long res{};
    for(int i=0;i<n;i++){
	res+=a[i]*b[i];
    }
    cout<<res;
    //now i will sort choose the bi to minize the sum
    return 0;
}

// 3 5 4 -1 4 3 2
