#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> D(n);
	rep(i,n) scanf("%d",&D[i]);

	if(count(D.begin(),D.end(),12)>=2) return puts("0"),0;
	if(count(D.begin(),D.end(), 0)>=1) return puts("0"),0;

	for(int d=1;d<12;d++) if(count(D.begin(),D.end(),d)>=3) return puts("0"),0;

	if(n+1>12) return puts("1"),0;

	int ans=0;
	rep(S,1<<n){
		vector<int> a(n+1);
		rep(i,n) a[i]=(S>>i&1?D[i]:24-D[i]);

		int tmp=24;
		rep(i,n+1) rep(j,i) tmp=min({tmp,abs(a[i]-a[j]),24-abs(a[i]-a[j])});
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}
