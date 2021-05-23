#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<int> ans(n);
	rep(i,(n+4)/5){
		vector<int> q(n);
		rep(j,5) if(5*i+j<n) q[5*i+j]=pow(10,j);

		printf("? ");
		rep(i,n) printf("%d%c",q[i],i<n-1?' ':'\n');
		fflush(stdout);

		int res; scanf("%d",&res);
		rep(j,5) if(5*i+j<n) {
			ans[5*i+j]=res%2;
			if(res%10>=8) res/=10;
			else          res/=10, res--;
		}
	}

	printf("! ");
	rep(i,n) printf("%d%c",ans[i],i<n-1?' ':'\n');
	fflush(stdout);

	return 0;
}
