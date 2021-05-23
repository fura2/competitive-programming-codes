#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q;
	lint T; scanf("%d%lld%d",&n,&T,&q);
	vector<lint> a(n);
	vector<int> d(n);
	rep(i,n) scanf("%lld%d",&a[i],&d[i]);

	rep(_,q){
		int x; scanf("%d",&x); x--;
		if(d[x]==1){
			int i;
			for(i=x+1;i<n;i++) if(d[i]==2) break;
			if(i==n) printf("%lld\n",a[x]+T);
			else     printf("%lld\n",min(a[x]+T,(a[i-1]+a[i])/2));
		}
		else{
			int i;
			for(i=x-1;i>=0;i--) if(d[i]==1) break;
			if(i==-1) printf("%lld\n",a[x]-T);
			else      printf("%lld\n",max(a[x]-T,(a[i]+a[i+1])/2));
		}
	}

	return 0;
}
