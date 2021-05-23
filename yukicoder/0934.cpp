#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> ans;
	rep(i,n){
		printf("? %d\n",n-1);
		rep(j,n) if(j!=i) printf("%d%c",j+1,j<n-1&&(j<n-2||i<n-1)?' ':'\n');
		fflush(stdout);
		int res; scanf("%d",&res);
		if(res==0) ans.emplace_back(i);
	}

	printf("! %lu\n",ans.size());
	rep(i,ans.size()) printf("%d%c",ans[i]+1,i+1<ans.size()?' ':'\n');
	fflush(stdout);

	return 0;
}
