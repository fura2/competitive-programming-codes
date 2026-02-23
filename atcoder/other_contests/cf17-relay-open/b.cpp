#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;

		if(n==1){
			printf("%d\n",min(u,v)+1);
			continue;
		}

		while(u!=v){
			if(u>v) u=(u-1)/n;
			else    v=(v-1)/n;
		}
		printf("%d\n",u+1);
	}

	return 0;
}
