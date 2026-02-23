#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]), B[i][j]--;

	vector cum(k,vector(h+1,vector(w+1,0)));
	rep(i,h) rep(j,w) cum[B[i][j]][i+1][j+1]++;
	rep(c,k) rep(i,h) rep(j,w) cum[c][i+1][j+1]+=cum[c][i+1][j]+cum[c][i][j+1]-cum[c][i][j];

	int q; scanf("%d",&q);
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==1){
			int i1,j1,i2,j2; scanf("%d%d%d%d",&i1,&j1,&i2,&j2); i1--; j1--; i2--; j2--;
			if(j1==j2){
				if(i1>i2) swap(i1,i2);
				for(int j=j1;j<w;j++){
					cum[B[i1][j1]][i1+1][j+1]--;
					cum[B[i2][j2]][i1+1][j+1]++;
				}
			}
			else{ // i1==i2
				if(j1>j2) swap(j1,j2);
				for(int i=i1;i<h;i++){
					cum[B[i1][j1]][i+1][j1+1]--;
					cum[B[i2][j2]][i+1][j1+1]++;
				}
			}
			swap(B[i1][j1],B[i2][j2]);
		}
		else{
			int l,t,r,b; scanf("%d%d%d%d",&t,&l,&b,&r); t--; l--;
			int ans1,ans2=-1;
			rep(c,k){
				int tmp=cum[c][b][r]-cum[c][b][l]-cum[c][t][r]+cum[c][t][l];
				if(tmp>=ans2){
					ans1=c;
					ans2=tmp;
				}
			}
			printf("%d %d\n",ans1+1,ans2);
		}
	}

	return 0;
}
