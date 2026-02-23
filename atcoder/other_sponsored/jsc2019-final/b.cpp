#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	bool a[300][300],b[300][300];
	rep(i,n){
		char s[301]; scanf("%s",s);
		rep(j,n) a[i][j]=(s[j]=='1');
	}
	rep(i,n){
		char s[301]; scanf("%s",s);
		rep(j,n) b[i][j]=(s[j]=='1');
	}

	bool ans[300][300];
	rep(i,n) rep(j,n) ans[i][j]=true;
	rep(i,n) rep(j,n) if(!b[i][j]) {
		rep(k,n) if(a[i][k]) ans[k][j]=false;
	}
	rep(i,n) rep(j,n) if(b[i][j]) {
		bool ok=false;
		rep(k,n) if(a[i][k] && ans[k][j]) ok=true;
		if(!ok){ puts("-1"); return 0; }
	}

	rep(i,n){ rep(j,n) printf("%d",ans[i][j]?1:0); puts(""); }

	return 0;
}
