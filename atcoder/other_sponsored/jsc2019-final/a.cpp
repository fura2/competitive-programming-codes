#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int a[200000],b[200000];
	rep(i,n) scanf("%d",a+i);
	rep(i,m) scanf("%d",b+i);

	static pair<int,int> ok[2000001];
	rep(i,2000001) ok[i].first=-1;

	rep(i,n) rep(j,m) {
		if(ok[a[i]+b[j]].first==-1){
			ok[a[i]+b[j]]={i,j};
		}
		else{
			printf("%d %d %d %d\n",ok[a[i]+b[j]].first,ok[a[i]+b[j]].second,i,j);
			return 0;
		}
	}
	puts("-1");

	return 0;
}
