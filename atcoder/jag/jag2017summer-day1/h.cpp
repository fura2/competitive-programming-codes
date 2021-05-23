#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

//const int INF=1<<29;
//const int dx[]={1,0,-1},dy[]={0,-1,1};

int main(){
	lint x,y; scanf("%lld%lld",&x,&y);

	if(x>y) swap(x,y);
	lint ans;
	if(y>0){
		if(x==y) ans=2*y;
		else     ans=2*(2*y-x)-3;
	}
	else if(y==0){
		ans=-2*x;
	}
	else{
		ans=2*(-x-y)-3;
	}
	printf("%lld\n",ans);

// experiment
/*
	int d[100][100][3];
	rep(i,100) rep(j,100) rep(k,3) d[i][j][k]=INF;

	const int OFS=50;
	queue<tuple<int,int,int>> Q;
	rep(k,3){
		d[OFS][OFS][k]=0;
		Q.emplace(0,0,k);
	}
	while(!Q.empty()){
		int y,x,k; tie(y,x,k)=Q.front(); Q.pop();
		if(abs(y)>=40 || abs(x)>=40) continue;
		rep(k2,3) if(k2!=k) {
			int y2=y+dy[k2],x2=x+dx[k2];
			if(d[y2+OFS][x2+OFS][k2]==INF){
				d[y2+OFS][x2+OFS][k2]=d[y+OFS][x+OFS][k]+1;
				Q.emplace(y2,x2,k2);
			}
		}
	}
	for(int y=-10;y<=10;y++){
		for(int x=-10;x<=10;x++){
			printf("%2d ",*min_element(d[y+OFS][x+OFS],d[y+OFS][x+OFS]+3));
		}
		puts("");
	}
*/
	return 0;
}
