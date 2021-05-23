#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int n,m,a[50],b[50];

int memo1[51][51][51][51][2];
int memo2[51][51][51][51][2];

int dfs2(int i,int j,int lasti,int lastj,int pass);

int dfs1(int i,int j,int lasti,int lastj,int pass){
	if(pass==2) return 0;

	int& res=memo1[i][j][lasti][lastj][pass];
	if(res!=-INF) return res;

	// 流す
	int sum=0;
	for(int ii=lasti;ii<i;ii++) if(a[ii]!=-1) sum+=a[ii];
	for(int jj=lastj;jj<j;jj++) if(b[jj]!=-1) sum-=b[jj];
	res=max(res,sum-dfs2(i,j,i,j,lasti==i&&lastj==j?pass+1:0));

	// カードを引く
	if(i<n){
		if(a[i]==-1){
			res=max(res,-dfs2(i+1,j,lasti,j,0));
		}
		else{
			res=max(res,-dfs2(i+1,j,lasti,lastj,0));
		}
	}

	return res;
}

int dfs2(int i,int j,int lasti,int lastj,int pass){
	if(pass==2) return 0;

	int& res=memo2[i][j][lasti][lastj][pass];
	if(res!=-INF) return res;

	int sum=0;
	for(int ii=lasti;ii<i;ii++) if(a[ii]!=-1) sum-=a[ii];
	for(int jj=lastj;jj<j;jj++) if(b[jj]!=-1) sum+=b[jj];
	res=max(res,sum-dfs1(i,j,i,j,lasti==i&&lastj==j?pass+1:0));

	if(j<m){
		if(b[j]==-1){
			res=max(res,-dfs1(i,j+1,i,lastj,0));
		}
		else{
			res=max(res,-dfs1(i,j+1,lasti,lastj,0));
		}
	}

	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	rep(i,n+1) rep(j,m+1) rep(lasti,n+1) rep(lastj,m+1) rep(pass,2) {
		memo1[i][j][lasti][lastj][pass]=-INF;
		memo2[i][j][lasti][lastj][pass]=-INF;
	}

	printf("%d\n",dfs1(0,0,0,0,0));

	return 0;
}
