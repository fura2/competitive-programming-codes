#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int deg[4]={};
	rep(i,3){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		deg[u]++;
		deg[v]++;
	}
	puts(count(deg,deg+4,3)==0?"YES":"NO");

	return 0;
}
