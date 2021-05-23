#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d; scanf("%d",&d);
	vector c(26,0);
	rep(j,26) scanf("%d",&c[j]);
	vector a(d,vector(26,0));
	rep(i,d) rep(j,26) scanf("%d",&a[i][j]);
	vector t(d,0);
	rep(i,d) scanf("%d",&t[i]), t[i]--;

	vector score(26,0),last(26,0);
	rep(i,d){
		score[t[i]]+=a[i][t[i]];
		last[t[i]]=i+1;
		rep(j,26) score[j]-=c[j]*(i+1-last[j]);
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int x,t2; scanf("%d%d",&x,&t2); x--; t2--;
		int t1=t[x];
		t[x]=t2;
		score[t1]=last[t1]=0;
		score[t2]=last[t2]=0;
		rep(i,d){
			if(t[i]==t1 || t[i]==t2){
				score[t[i]]+=a[i][t[i]];
				last[t[i]]=i+1;
			}
			score[t1]-=c[t1]*(i+1-last[t1]);
			score[t2]-=c[t2]*(i+1-last[t2]);
		}
		printf("%d\n",accumulate(score.begin(),score.end(),0));
	}

	return 0;
}
