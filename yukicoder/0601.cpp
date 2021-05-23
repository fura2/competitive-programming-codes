#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int cnt[2][2]={};
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		cnt[x%2][y%2]++;
	}

	int sum=0;
	rep(i,2) rep(j,2) sum+=cnt[i][j]/2;
	puts(sum%2==1?"Alice":"Bob");

	return 0;
}
