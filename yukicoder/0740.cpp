#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,p,q; scanf("%d%d%d%d",&n,&m,&p,&q);

	int ans=0,t=1;
	while(n>0){
		if(p<=t && t<p+q) n-=2*m;
		else n-=m;
		t++;
		if(t>12) t=1;
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
