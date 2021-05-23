#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int h=19,w=6;
string B[19];

lint memo[19][6][1<<6][1<<6];

lint dfs(int i,int j,int S1,int S2){
	if(j==w) return dfs(i+1,0,S1,S2);
	if(i==h) return 1;

	lint& res=memo[i][j][S1][S2];
	if(res!=-1) return memo[i][j][S1][S2];

	res=0;
	rep(d,2){
		if(B[i][j]=='0'+d || B[i][j]=='?'){
			int tar=S2>>j&1,a[5];
			a[0]=tar;
			a[1]=(j> 0 ?S1>>(j-1)&1:0);
			a[2]=(j<w-1?S2>>(j+1)&1:0);
			a[3]=S1>>j&1;
			a[4]=d;
			sort(a,a+5);
			if(a[2]==tar){
				int S12=S1,S22=S2;
				S12&=~(1<<j);
				S12|=(S2>>j&1)<<j;
				S22&=~(1<<j);
				S22|=d<<j;
				res+=dfs(i,j+1,S12,S22);
			}
		}
	}
	return res;
}

int main(){
	rep(i,h-1) cin>>B[i];
	B[h-1]="000000";

	memset(memo,-1,sizeof memo);
	printf("%lld\n",dfs(0,0,0,0));

	return 0;
}
