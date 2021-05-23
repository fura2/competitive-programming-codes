#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	printf("? ");
	rep(i,n) printf("%d%c",i+1,i<n-1?' ':'\n');
	fflush(stdout);
	char s[5]; scanf("%s",s);
	char L0=s[0];
	char R0=(L0=='R'?'B':'R');

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		printf("? ");
		rep(i,n) printf("%d%c",mi+i+1,i<n-1?' ':'\n');
		fflush(stdout);
		scanf("%s",s);

		if(s[0]==L0) lo=mi;
		else         hi=mi;
	}

	vector<int> ans(2*n,-1);
	ans[lo]=0;
	ans[lo+n]=1;
	rep(k,2*n) if(k<lo || lo+n<k) {
		printf("? ");
		rep(i,n-1) printf("%d ",lo+i+2);
		printf("%d\n",k+1);
		fflush(stdout);
		scanf("%s",s);
		ans[k]=(s[0]==L0?0:1);
	}
	for(int k=lo+1;k<lo+n;k++){
		printf("? ");
		rep(i,lo) printf("%d ",i+1);
		for(int i=lo+n+1;i<2*n;i++) printf("%d ",i+1);
		printf("%d\n",k+1);
		fflush(stdout);
		scanf("%s",s);
		ans[k]=(s[0]==L0?0:1);
	}

	printf("! ");
	rep(i,2*n) putchar(ans[i]==0?L0:R0);
	puts("");

	return 0;
}
