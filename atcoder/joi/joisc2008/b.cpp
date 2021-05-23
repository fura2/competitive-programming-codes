// Day 1: Sheet

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h,w; scanf("%d%d%d",&n,&w,&h);
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	vector t(n+1,h),l(n+1,w),b(n+1,0),r(n+1,0);
	for(int c=1;c<=n;c++){
		rep(i,h) rep(j,w) if(B[i][j]==c) {
			t[c]=min(t[c],i);
			l[c]=min(l[c],j);
			b[c]=max(b[c],i+1);
			r[c]=max(r[c],j+1);
		}
	}

	static int cum[1001][101][101];
	rep(i,h) rep(j,w) if(B[i][j]!=0) cum[B[i][j]][i+1][j+1]++;
	for(int c=1;c<=n;c++){
		rep(i,h) rep(j,w) cum[c][i+1][j+1]+=cum[c][i+1][j]+cum[c][i][j+1]-cum[c][i][j];
	}

	vector<int> ans;
	vector<bool> used(n+1);
	rep(_,n){
		int c;
		for(c=1;c<=n;c++) if(!used[c]) {
			if((t[c]>b[c] && l[c]>r[c])
			|| cum[c][b[c]][r[c]]-cum[c][b[c]][l[c]]-cum[c][t[c]][r[c]]+cum[c][t[c]][l[c]]
			  +cum[0][b[c]][r[c]]-cum[0][b[c]][l[c]]-cum[0][t[c]][r[c]]+cum[0][t[c]][l[c]]
			  ==(b[c]-t[c])*(r[c]-l[c]))
				break;
		}

		ans.emplace_back(c);
		rep(i,h+1) rep(j,w+1) cum[0][i][j]+=cum[c][i][j];
		used[c]=true;
	}

	reverse(ans.begin(),ans.end());
	rep(i,n) printf("%d%c",ans[i],i<n-1?' ':'\n');

	return 0;
}
