#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m,n,k; scanf("%d%d%d",&m,&n,&k);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]), x[i]--;

	int ans=0;
	rep(g,m){
		vector<bool> f(k+1);
		rep(i,n){
			int d=abs(x[i]-g);
			if(1<=d && d<=k) f[d]=true;
		}
		ans=max<int>(ans,count(x.begin(),x.end(),g)+count(f.begin(),f.end(),true));
	}
	printf("%d\n",ans);

	return 0;
}
