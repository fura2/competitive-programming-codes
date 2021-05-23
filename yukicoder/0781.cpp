#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);

	static int cnt[10000001];
	for(int i=0;i*i<=y;i++){
		for(int j=1;i*i+j*j<=y;j++){
			cnt[i*i+j*j]++;
		}
	}

	int ans=0;
	for(int i=x;i<=y;i++) ans=max(ans,cnt[i]);
	printf("%d\n",4*ans);

	return 0;
}
