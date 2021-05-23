#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int cnt=0;
map<pair<int,int>,int> memo;

int ask(int x,int y){
	if(memo.count({x,y})>0) return memo[{x,y}];

	printf("%d %d\n",x,y);
	fflush(stdout);

	int res; scanf("%d",&res);
	memo[{x,y}]=res;
	if(res==0) exit(0);
	return res;
}

double phi=(sqrt(5)+1)/2;

int main(){
	int x0,y0;

	int lo=0,hi=1e5;
	while(hi-lo>3){
		int mi1=hi-(hi-lo)/phi;
		int mi2=lo+(hi-lo)/phi;
		if(ask(mi1,0)<ask(mi2,0)) hi=mi2;
		else                      lo=mi1;
	}
	int mn=INF,i_mn;
	for(int i=lo;i<=hi;i++){
		int tmp=ask(i,0);
		if(tmp<mn) mn=tmp, i_mn=i;
	}
	x0=i_mn;

	lo=0; hi=1e5;
	while(hi-lo>3){
		int mi1=hi-(hi-lo)/phi;
		int mi2=lo+(hi-lo)/phi;
		if(ask(x0,mi1)<ask(x0,mi2)) hi=mi2;
		else                        lo=mi1;
	}
	mn=INF;
	for(int i=lo;i<=hi;i++){
		int tmp=ask(x0,i);
		if(tmp<mn) mn=tmp, i_mn=i;
	}
	y0=i_mn;

	ask(x0,y0);

	return 0;
}
