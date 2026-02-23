#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int f[]={0,0,0,0,0,0,1,1,2,3};

	int h,w; scanf("%d%d",&h,&w);
	int a[100][100];
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	bool zero=true;
	rep(i,h) rep(j,w) if(a[i][j]!=0) zero=false;
	if(zero) return puts("Yes 0"),0;

	bool five=false;
	rep(i,h) rep(j,w) if(a[i][j]==5) five=true;
	if(!five) return puts("No"),0;

	if(w==1){
		rep(i,h) a[0][i]=a[i][0];
		swap(h,w);
	}
	if(h==1){
		int ans=INF;
		rep(j,w) if(a[0][j]==5) {
			int l=0,r=0;
			rep(x,j) l=max(l,a[0][x]);
			for(int x=j+1;x<w;x++) r=max(r,a[0][x]);
			ans=min(ans,f[l]+f[r]+1);
		}
		printf("Yes %d\n",ans);
		return 0;
	}

	int mx=0;
	rep(i,h) rep(j,w) mx=max(mx,a[i][j]);
	printf("Yes %d\n",f[mx]+1);

	return 0;
}
