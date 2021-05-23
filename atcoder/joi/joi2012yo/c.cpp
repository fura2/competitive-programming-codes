#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b,c; scanf("%d%d%d%d",&n,&a,&b,&c);
	vector<int> d(n);
	rep(i,n) scanf("%d",&d[i]);

	sort(d.rbegin(),d.rend());

	int ans=0,sum=c;
	rep(i,n+1){
		ans=max(ans,sum/(a+i*b));
		if(i<n) sum+=d[i];
	}
	printf("%d\n",ans);

	return 0;
}
