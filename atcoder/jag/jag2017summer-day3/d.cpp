#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[14];
double p[14][3];

double memo[1<<14];

double dfs(int S){
	double& res=memo[S];
	if(res!=-1) return res;

	if(S==1) return res=1;
	assert(S&1);

	bool b=true; // あいこで優勝できるか
	for(int i=1;i<n;i++) if(S>>i&1 && a[0]<a[i]) b=false;

	res=0;
	rep(x,3){ // 自分が手 x を出す
		double tmp=0;
		for(int T=S-1;T>=0;T--){ // T が勝ち残る
			T&=S;
			if(~T&1) continue;

			double q=1; // T が勝ち残る確率
			for(int i=1;i<n;i++) if(S>>i&1) {
				if(T>>i&1) q*=p[i][x];
				else       q*=p[i][(x+1)%3];
			}
			if(b && T==1){
				double r0=1,r1=1,r2=1,r01=1,r02=1,r12=1;
				for(int i=1;i<n;i++) if(S>>i&1) {
					r0*=p[i][0];
					r1*=p[i][1];
					r2*=p[i][2];
					r01*=p[i][0]+p[i][1];
					r02*=p[i][0]+p[i][2];
					r12*=p[i][1]+p[i][2];
				}
				double r; // あいこになる確率
				if     (x==0) r=1-(r01+r02-2*r0);
				else if(x==1) r=1-(r01+r12-2*r1);
				else          r=1-(r02+r12-2*r2);
				q+=r;
			}
			tmp+=q*dfs(T);
		}
		res=max(res,tmp);
	}
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
		if(i>0){
			scanf("%lf%lf%lf",&p[i][0],&p[i][2],&p[i][1]);
			rep(j,3) p[i][j]/=100;
		}
	}

	rep(S,1<<n) memo[S]=-1;
	printf("%.9f\n",dfs((1<<n)-1));

	return 0;
}
