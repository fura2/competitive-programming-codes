#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
// experiment
/*
	bool dp[100][100]={};
	rep(a,30) rep(b,30) if(a+b>0) {
		rep(c,max(a,b)+1){
			int d;
			d=a-c;
			if(a>0 && 0<=c && c<=a && 0<=d && d<=b && !dp[a-c][b-d]) dp[a][b]=true;
			d=b-c;
			if(b>0 && 0<=c && c<=a && 0<=d && d<=b && !dp[a-c][b-d]) dp[a][b]=true;
		}
	}

	rep(a,20){
		rep(b,20) printf("%d ",!!dp[a][b]);
		puts("");
	}
*/
	int a,b; scanf("%d%d",&a,&b);
	puts(a%2==0||b%2==0?"Yes":"No");

	return 0;
}
