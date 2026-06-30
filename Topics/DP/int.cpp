#include <bits/stdc++.h> 

using namespace std; 

int main() {
    int n,k;
    std::string_view s;
    cin>>n>>k;
    vector<int> v(n);
    for (int i=1;i<n;i++){
	int orr,andd;
	printf("and 1 %d\n",i+1);
	fflush(stdout);
	scanf("%d",&andd);
	printf("or 1 %d\n",i+1);
	fflush(stdout);
	scanf("%d",&orr);
	v[i]=~(~orr|andd)+2*andd;
    }
    int orr,andd;
    printf("and %d %d\n",2,3);
    fflush(stdout);
    scanf("%d",&andd);
    printf("or %d %d\n",2,3);
    fflush(stdout);
    scanf("%d",&orr);
    v[0]=~(~orr|andd)+2*andd;
    v[0]=(v[1]+v[2]-v[0])/2;
    for (int i=0;i<n;i++){
	if (i==0) continue;
	v[i]-=v[0];
    }
    sort(v.begin(),v.end());
    printf("finish %d\n",v[k-1]);
}
// 7 6 0 7 0 5 0 3 1 3 1 5 0 5 4 6
