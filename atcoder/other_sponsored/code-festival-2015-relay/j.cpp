#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
// experiment
/*
	bool dp[31][31]={};
	rep(a,31) dp[a][0]=true;
	rep(b,31) dp[0][b]=true;
	for(int a=1;a<=30;a++) for(int b=1;b<=30;b++) {
		int mn=min(a,b);
		for(int x=1;x<=mn;x++){
			dp[a][b]|=!dp[a-x][b];
			dp[a][b]|=!dp[a][b-x];
		}
	}
	rep(a,31) rep(b,31) printf("%c%c",dp[a][b]?'o':'-',b<30?' ':'\n');
*/

	int a,b; scanf("%d%d",&a,&b);
	if(a>b) swap(a,b);
	if(a==1){
		puts(b%2==1?"rng":"snuke");
	}
	else if(a==2){
		puts(b%4==2?"rng":"snuke");
	}
	else if(a==3){
		puts(b>=8&&b%4==0?"rng":"snuke");
	}
	else if(a==4){
		puts(b==4?"rng":"snuke");
	}
	else{
		puts("snuke");
	}

	return 0;
}
