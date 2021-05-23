#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint dfs(int a,int base){
	lint res=(a+base-2)/(base-1);
	if(a>0){
		lint cnt=1;
		if(a%base!=0) cnt++;
		res=min(res,cnt+dfs(a/base,base));
	}
	return res;
}

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int a,b,base; scanf("%d%d%d",&a,&b,&base);
		if(base==1) puts("-1");
		else        printf("%lld\n",b*dfs(a,base));
	}
	return 0;
}
