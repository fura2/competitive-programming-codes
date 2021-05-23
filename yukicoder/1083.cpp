#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
vector<int> a;

int dfs(int S,int x){
	if(S==(1<<n)-1) return x;

	int S2=S;
	rep(i,n) if((S>>i&1)==0 && x<a[i]) S2|=1<<i;
	if(S2!=S) return dfs(S2,x);

	int res=0;
	rep(i,n) if((S>>i&1)==0) res=max(res,dfs(S|1<<i,x%a[i]));
	return res;
}

int main(){
	int x; scanf("%d%d",&n,&x);
	a.resize(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	n=a.size();

	printf("%d\n",dfs(0,x));

	return 0;
}
