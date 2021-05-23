#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; scanf("%d%d",&n,&d);

	vector<int> cnt(2*n*n+1);
	for(int x=1;x<=n;x++) for(int y=1;y<=n;y++) cnt[x*x+y*y]++;

	int ans=0;
	for(int z=1;z<=n;z++) for(int w=1;w<=n;w++) {
		int tar=w*w+d-z*z;
		if(0<=tar && tar<=2*n*n) ans+=cnt[tar];
	}
	printf("%d\n",ans);

	return 0;
}
