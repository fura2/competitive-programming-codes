#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,l; scanf("%d%d",&n,&l);
	int t=0,pos=0;
	rep(i,n){
		int x,w,T; scanf("%d%d%d",&x,&w,&T);
		t+=x-pos;
		if(t%(2*T)>=T || t%(2*T)+w>T) t=(t+2*T-1)/(2*T)*(2*T);
		t+=w;
		pos=x+w;
	}
	t+=l-pos;
	printf("%d\n",t);
	return 0;
}
