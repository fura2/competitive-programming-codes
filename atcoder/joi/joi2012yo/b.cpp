#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int score[100]={};
	rep(i,n*(n-1)/2){
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d); a--; b--;
		if     (c>d) score[a]+=3;
		else if(c<d) score[b]+=3;
		else         score[a]++, score[b]++;
	}

	int ans[100];
	for(int r=1;r<=n;){
		int mx=*max_element(score,score+n);
		int cnt=0;
		rep(i,n) if(score[i]==mx) {
			score[i]=-1;
			ans[i]=r;
			cnt++;
		}
		r+=cnt;
	}
	rep(i,n) printf("%d\n",ans[i]);

	return 0;
}
