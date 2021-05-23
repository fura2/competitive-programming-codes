#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int memo[201][201][201];

int ask(int x,int y,int z){
	int& res=memo[x+100][y+100][z+100];
	if(res!=-1) return res;

	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	int d; scanf("%d",&d);
	return res=d;
}

int solve(int i){
	int lo=-100,hi=101;
	while(hi-lo>1){
		int mi=(lo+hi)/2-1;
		int d1,d2;
		if(i==0) d1=ask(mi,0,0), d2=ask(mi+1,0,0);
		if(i==1) d1=ask(0,mi,0), d2=ask(0,mi+1,0);
		if(i==2) d1=ask(0,0,mi), d2=ask(0,0,mi+1);
		if(d1<=d2) hi=mi+1;
		else       lo=mi+1;
	}
	return lo;
}

int main(){
	memset(memo,-1,sizeof memo);
	int x=solve(0);
	int y=solve(1);
	int z=solve(2);
	printf("! %d %d %d\n",x,y,z);
	return 0;
}
