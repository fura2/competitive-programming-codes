#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int color[200000],nxt[200000];

int go(int i,int r,int c){
	if(i>=r) return i;
	if(color[i]==0) color[i]=c;
	return nxt[i]=go(nxt[i],r,c);
}

int main(){
	int n,q; scanf("%d%d",&n,&q);

	rep(i,n) nxt[i]=i+1;

	rep(_,q){
		int l,r;
		char c; scanf("%d%d %c",&l,&r,&c); l--;
		go(l,r,c);
	}

	int ans[3]={};
	rep(i,n){
		if(color[i]=='Y') ans[0]++;
		if(color[i]=='K') ans[1]++;
		if(color[i]=='C') ans[2]++;
	}
	rep(i,3) printf("%d%c",ans[i],i<2?' ':'\n');

	return 0;
}
