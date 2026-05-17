#include <bits/stdc++.h>
using namespace std;

struct op{
    int l,r,d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<long long>v(n);
    vector<long long>diff(n+1);
    vector<op>op(m);
    vector<long long>freq(m+2);
    vector<long long>prefix(n+2);
    vector<long long>diff_freq(m+2);
    for(int i=0;i<n;i++){
	cin>>v[i];
    }
    //i will need to create a diff array
    for(int i=0;i<m;i++){
	int l,r,d;
	cin>>l>>r>>d;
	op[i]={l,r,d};
    }
    for(int i=0;i<k;i++){
	int x,y;
	cin>>x>>y;
	x--;
	y--;
	diff_freq[x]++;
	diff_freq[y+1]--;
    }
    for(int i=0;i<m+1;i++){
	freq[i+1]=freq[i]+diff_freq[i];
    }
	//    for(int i=0;i<=m+1;i++){
	// fprintf(stderr,"the number of times the op %d is applied is %d\n",i,freq[i]);
	//    }
    //creating the diff array for the op
    for(int i=1;i<=m;i++){
	diff[op[i-1].l-1]+=op[i-1].d*freq[i];
	diff[op[i-1].r]-=op[i-1].d*freq[i];
    }
    for(int i=0;i<n+1;i++){
	prefix[i+1]=prefix[i]+diff[i];
    }
    for(int i=0;i<n;i++){
	cout<<v[i]+prefix[i+1]<<' ';
    }
	//    for(int i=0;i<n+1;i++){
	// fprintf(stderr,"the number that will be added to each cell %d is applied is %d\n",i,prefix[i]);
	//    }

    return 0;
}
