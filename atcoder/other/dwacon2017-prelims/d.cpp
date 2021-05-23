#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int x[100000],y[100000];
	rep(i,n) scanf("%d%d",x+i,y+i);

	m=min(m,n);

	int sum1=0,sum2=0;
	multiset<int> S;
	rep(i,m){
		sum1+=y[i];
		sum2+=x[i]-y[i];
		S.emplace(x[i]-y[i]);
	}
	int ans=sum1+sum2;
	rep(i,n-m){
		sum1+=y[m+i];
		sum2-=*S.begin();
		S.erase(S.begin());
		sum2+=x[m+i]-y[m+i];
		S.emplace(x[m+i]-y[m+i]);
		ans=max(ans,sum1+sum2);
	}
	printf("%d\n",ans);

	return 0;
}
