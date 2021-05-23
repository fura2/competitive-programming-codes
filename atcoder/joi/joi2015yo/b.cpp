#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m);
	rep(i,m) scanf("%d",&a[i]), a[i]--;

	vector<int> ans(n);
	rep(i,m){
		vector<int> b(n);
		rep(j,n) scanf("%d",&b[j]), b[j]--;

		rep(j,n){
			if(b[j]==a[i]) ans[j]++;
			else           ans[a[i]]++;
		}
	}
	rep(j,n) printf("%d\n",ans[j]);

	return 0;
}
