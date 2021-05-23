#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int res[3][3]={
		{0,1,2},
		{2,0,1},
		{1,2,0}};
	char ans[3][8]={"Drew","Won","Lost"};
	puts(ans[res[n][k]]);
	return 0;
}
