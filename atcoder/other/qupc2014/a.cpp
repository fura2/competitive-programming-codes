#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,b,m,d; scanf("%d%d%d%d",&n,&b,&m,&d);
	vector e(m,vector(n,0));
	rep(i,m) rep(j,n) scanf("%d",&e[i][j]);

	for(int th=100;th>=0;th--){
		int res=0;
		rep(i,m){
			int cnt=0;
			rep(j,n) if(e[i][j]>=th) cnt++;
			if(cnt>=b) res++;
		}
		if(res>=d){
			printf("%d\n",th);
			break;
		}
	}

	return 0;
}
