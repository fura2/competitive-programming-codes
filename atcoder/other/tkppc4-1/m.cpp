#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool ask(int l1,int r1,int l2=-1,int r2=-1){
	printf("? %d",r1-l1+r2-l2);
	for(int i=l1;i<r1;i++) printf(" %d",i+1);
	for(int i=l2;i<r2;i++) printf(" %d",i+1);
	puts("");
	fflush(stdout);

	char s[8]; scanf("%s",s);
	return s[0]=='R';
}

void solve(int l,int r){
	if(r-l==2){
		printf("! %d %d\n",l+1,l+2);
		return;
	}

	int m=(l+r)/2;
	if(r-l>4096) m=r-2048;

	if(ask(l,m)){
		solve(l,m);
		return;
	}

	if(ask(m,r)){
		solve(m,r);
		return;
	}

	int lo=l,hi=m;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(ask(lo,mi,m,r)) hi=mi;
		else               lo=mi;
	}
	int ans1=lo;

	lo=m; hi=r;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(ask(l,m,lo,mi)) hi=mi;
		else               lo=mi;
	}
	int ans2=lo;

	printf("! %d %d\n",ans1+1,ans2+1);
}

int main(){
	int n; scanf("%d",&n);
	solve(0,n);
	return 0;
}
