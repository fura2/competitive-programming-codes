#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	int pos[128];
	rep(c,128) pos[c]=-1;

	lint ans=0;
	for(int i=n-1;i>=0;i--){
		pos[s[i]]=i;

		int m=0,a[26];
		for(int c='a';c<='z';c++) if(pos[c]!=-1) a[m++]=pos[c];
		sort(a,a+m);
		a[m++]=n;

		rep(j,m-1) ans+=(j+1)*(a[j+1]-a[j]);
	}
	printf("%.9f\n",ans/(n*(n+1.0)/2));

	return 0;
}
