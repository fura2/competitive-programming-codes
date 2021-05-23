#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve(const vector<int>& a,const vector<int>& b){
	int idx=0;
	rep(i,a.size()){
		if(idx<b.size() && b[idx]==a[i]) idx++;
	}
	return idx;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	int ans=0;
	rep(j,m){
		ans=max(ans,solve(a,b));
		b.erase(b.begin());
	}
	printf("%d\n",ans);

	return 0;
}
