#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	int cnt[3]={};
	rep(i,n){
		int p; scanf("%d",&p);
		if     (p<=a) cnt[0]++;
		else if(p<=b) cnt[1]++;
		else          cnt[2]++;
	}
	printf("%d\n",min({cnt[0],cnt[1],cnt[2]}));
	return 0;
}
