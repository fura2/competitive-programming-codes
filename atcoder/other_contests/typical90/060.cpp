#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

vector<int> f(vector<int> a){
	int n=a.size();
	vector<int> res(n),inc(n+1,INF);
	inc[0]=0;
	rep(i,n){
		int idx=lower_bound(inc.begin(),inc.end(),a[i])-inc.begin();
		res[i]=idx;
		inc[idx]=a[i];
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	auto lis=f(a);
	reverse(a.begin(),a.end());
	auto lds=f(a);

	int ans=0;
	rep(i,n) ans=max(ans,lis[i]+lds[n-i-1]-1);
	printf("%d\n",ans);

	return 0;
}
