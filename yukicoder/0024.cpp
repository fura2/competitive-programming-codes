#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	bool f[10];
	rep(x,10) f[x]=true;

	rep(i,n){
		int a,b,c,d;
		char s[8]; scanf("%d%d%d%d%s",&a,&b,&c,&d,s);

		bool g[10]={};
		g[a]=true;
		g[b]=true;
		g[c]=true;
		g[d]=true;

		if(s[0]=='Y'){
			rep(x,10) if(!g[x]) f[x]=false;
		}
		else{
			rep(x,10) if(g[x]) f[x]=false;
		}
	}

	rep(x,10) if(f[x]) printf("%d\n",x);

	return 0;
}
