#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	char B[500][501];
	rep(i,n) scanf("%s",B[i]);

	bool ok=false;
	int fil=0;
	rep(j,n){
		int c=0;
		rep(i,n) if(B[i][j]=='#') ok=true, c++;
		if(c==n) fil++;
	}
	if(!ok) return puts("-1"),0;

	long ans=INF;
	rep(i,n){
		bool ok=false;
		rep(k,n) if(B[k][i]=='#') ok=true;
		ans=min(ans,count(B[i],B[i]+n,'.')+(ok?0:1));
	}
	ans+=n-fil;
	printf("%ld\n",ans);

	return 0;
}
