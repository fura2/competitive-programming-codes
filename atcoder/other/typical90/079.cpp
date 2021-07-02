#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector A(h,vector(w,0));
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&A[i][j]);
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	lint ans=0;
	rep(i,h-1) rep(j,w-1) {
		int d=B[i][j]-A[i][j];
		ans+=abs(d);
		rep(dx,2) rep(dy,2) {
			A[i+dx][j+dy]+=d;
		}
	}
	rep(i,h) rep(j,w) if(A[i][j]!=B[i][j]) {
		puts("No");
		return 0;
	}
	printf("Yes\n%lld\n",ans);

	return 0;
}
