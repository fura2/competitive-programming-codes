#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	vector<int> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+(s[i]=='A'?1:-1);

	const int OFS=n;
	vector<int> pos(2*n+1,-1);
	rep(i,n+1) pos[sum[i]+OFS]=i;

	int ans=0;
	rep(i,n) ans=max(ans,pos[sum[i]+OFS]-i);
	printf("%d\n",ans);

	return 0;
}
