#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

lint B[10000][160];

void subst(int y,int x,int b){
	if(b==0) B[y][x/64]&=~(1LL<<x%64);
	else     B[y][x/64]|=1LL<<x%64;
}

int get(int y,int x){
	return B[y][x/64]>>x%64&1;
}

int main(){
	int n,type; scanf("%d%d",&n,&type);
	vector<int> t(n),l(n),b(n),r(n);
	rep(i,n) scanf("%d%d%d%d",&l[i],&t[i],&r[i],&b[i]);

	rep(y,10000){
		static int cum[10001];
		rep(x,10001) cum[x]=0;
		rep(i,n) if(t[i]<=y && y<b[i]) {
			cum[l[i]]++;
			cum[r[i]]--;
		}
		rep(x,10000) cum[x+1]+=cum[x];
		rep(x,10000) if(cum[x]>0) subst(y,x,1);
	}

	int area=0,peri=0;
	rep(y,10000) rep(x,10000) if(get(y,x)==1) {
		area++;
		rep(k,4){
			int y2=y+dy[k],x2=x+dx[k];
			if(y2<0 || 10000<=y2 || x2<0 || 10000<=x2 || get(y2,x2)==0) peri++;
		}
	}
	printf("%d\n",area);
	if(type==2) printf("%d\n",peri);

	return 0;
}
