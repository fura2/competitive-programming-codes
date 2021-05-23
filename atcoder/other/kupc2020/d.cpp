#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int d;
	for(d=2;d<n;d++) if(n%d==0) break;
	if(d==n){
		puts("impossible");
		return 0;
	}

	if(n%2==0){
		printf("%d\n",n/2);
		rep(i,n/2) printf("2 %d %d\n",2*i+1,2*n-2*i-1);
		return 0;
	}

	vector ans(d,vector<int>());
	rep(i,d){
		rep(j,d){
			ans[i].emplace_back((i+j)%d);
		}
		assert((n/d-d)%2==0);
		rep(j,(n/d-d)/2){
			ans[i].emplace_back(i);
			ans[i].emplace_back(d-i-1);
		}
	}
	rep(i,d) rep(j,n/d) ans[i][j]=2*j*d+1+2*ans[i][j];

	printf("%d\n",d);
	rep(i,d){
		printf("%d ",n/d);
		rep(j,n/d) printf("%d%c",ans[i][j],j<n/d-1?' ':'\n');
	}

	return 0;
}
