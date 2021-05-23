#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<double> p(n+2); // p[i] = (サイコロを i 回振ったときにゲームが終わる確率)
	double tmp=1;
	p[1]=0;
	for(int i=2;i<=n+1;i++){
		tmp-=p[i-1];
		p[i]=tmp*(i-1)/n;
	}

	double ans=0;
	for(int i=1;i<=n;i++) ans+=p[i+1]*i*(n+1)/2;
	printf("%.9f\n",ans);

	return 0;
}
