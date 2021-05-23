#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);

	if(d==10) return puts("Impossible"),0;

	puts("Possible");
	int ans=0,cnt=0;
	rep(i,b){
		ans+=50*(1<<(cnt/100));
		cnt++;
	}
	rep(i,a){
		ans+=100*(1<<(cnt/100));
		cnt++;
	}
	printf("%d\n",ans);

	return 0;
}
