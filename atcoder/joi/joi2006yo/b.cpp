#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	char f[128]={};
	rep(i,n){
		char a,b; scanf(" %c %c",&a,&b);
		f[a]=b;
	}

	int m; scanf("%d",&m);
	rep(i,m){
		char c; scanf(" %c",&c);
		putchar(f[c]==0?c:f[c]);
	}
	puts("");

	return 0;
}
