// only for subtasks 1, 2, 3, 4, 5, 6
// O(H*W^2*log(H))

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int h,w;
char B[5002][5003];
int sum[5003][5003];

inline int f(int t,int l,int b,int r){ return sum[b][r]-sum[b][l]-sum[t][r]+sum[t][l]; }

lint subtask6(){
	lint res=0;
	rep(i,h-1){
		rep(l,w) for(int r=l+1;r<=w;r++) {
			if(f(i,l,i+1,r)>0 || f(i+1,l,i+2,r)==0) continue;
			int lo=0,hi=i;
			while(hi-lo>1){
				int mi=(lo+hi)/2;
				if(f(mi,l,i+1,r)==0) hi=mi;
				else                 lo=mi;
			}
			if(f(hi,l-1,i+1,r)>0 && f(hi,l,i+1,r+1)>0) res++;
		}
	}
	return res;
}

lint subtask4(){
	if(f(1,1,h-1,w-1)==0) return 1;

	vector<int> Y{0},X{0};
	rep(i,h-2) if(f(i+1,1,i+2,w-1)>0) Y.emplace_back(i+1);
	rep(j,w-2) if(f(1,j+1,h-1,j+2)>0) X.emplace_back(j+1);
	Y.emplace_back(h-1);
	X.emplace_back(w-1);

	static char tmp[5003][5003];
	rep(i,Y.size()) rep(j,X.size()) tmp[i][j]=B[Y[i]][X[j]];
	h=Y.size();
	w=X.size();
	rep(i,h) rep(j,w+1) B[i][j]=tmp[i][j];

	rep(i,h) rep(j,w) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+(B[i][j]=='#'?1:0);

	lint res=0;
	rep(i,h-1) if(Y[i+1]-Y[i]>1) res++;
	rep(j,w-1) if(X[j+1]-X[j]>1) res++;
	res+=subtask6();
	return res;
}

int main(){
	int n; scanf("%d%d%d",&h,&w,&n);
	rep(j,w+2) B[0][j]=B[h+1][j]='#';
	rep(i,h){
		B[i+1][0]=B[i+1][w+1]='#';
		rep(j,w) B[i+1][j+1]='.';
	}
	rep(i,n){
		int y,x; scanf("%d%d",&y,&x);
		B[y][x]='#';
	}
	h+=2;
	w+=2;

	rep(i,h) rep(j,w) sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+(B[i][j]=='#'?1:0);

	lint ans;
	if(n<=10) ans=subtask4();
	else      ans=subtask6();
	printf("%lld\n",ans);

	return 0;
}
