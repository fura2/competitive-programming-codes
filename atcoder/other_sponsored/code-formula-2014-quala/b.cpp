#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	int cnt[10]={};
	rep(i,a+b){
		int x; scanf("%d",&x);
		if(x==0) x=10;
		x--;
		cnt[x]+=(i<a?1:2);
	}

	const char* f="x.o";
	printf("%c %c %c %c\n",f[cnt[6]],f[cnt[7]],f[cnt[8]],f[cnt[9]]);
	printf(" %c %c %c\n",f[cnt[3]],f[cnt[4]],f[cnt[5]]);
	printf("  %c %c\n",f[cnt[1]],f[cnt[2]]);
	printf("   %c\n",f[cnt[0]]);

	return 0;
}
