#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,n; scanf("%d%d",&h,&n);

	int ans=1;
	rep(i,n-1){
		int a; scanf("%d",&a);
		if(a>h) ans++;
	}
	printf("%d%s\n",ans,ans%10==1?"st":ans%10==2?"nd":ans%10==3?"rd":"th");

	return 0;
}
