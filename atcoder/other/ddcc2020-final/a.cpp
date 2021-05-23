#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int grundy(int a){
	if(a==1) return 0;

	bool g[9]={};
	for(int d=1;d*d<=a;d++) if(a%d==0) {
		g[grundy(d)]=true;
		if(d>1 && d*d<a) g[grundy(a/d)]=true;
	}
	rep(i,9) if(!g[i]) return i;
	return -1;
}

int main(){
	int n; scanf("%d",&n);

	int g=0;
	rep(i,n){
		int a; scanf("%d",&a);
		g^=grundy(a);
	}
	puts(g>0?"Yes":"No");

	return 0;
}
