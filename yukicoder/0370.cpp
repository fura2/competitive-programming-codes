#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> x(m);
	rep(i,m) scanf("%d",&x[i]);

	sort(x.begin(),x.end());

	int ans=INF;
	rep(i,m-n+1){
		if(x[i]>=0){
			ans=min(ans,x[i+n-1]);
		}
		else if(x[i+n-1]<0){
			ans=min(ans,-x[i]);
		}
		else{
			ans=min({ans,-2*x[i]+x[i+n-1],2*x[i+n-1]-x[i]});
		}
	}
	printf("%d\n",ans);

	return 0;
}
