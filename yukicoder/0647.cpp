#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);
	int m; scanf("%d",&m);
	vector<int> x(m),y(m);
	rep(j,m) scanf("%d%d",&x[j],&y[j]);

	vector<int> cnt(m);
	rep(i,n){
		 rep(j,m) if(x[j]<=a[i] && y[j]>=b[i]) cnt[j]++;
	}
	int mx=*max_element(cnt.begin(),cnt.end());

	if(mx==0) return puts("0"),0;
	rep(j,m) if(cnt[j]==mx) printf("%d\n",j+1);

	return 0;
}
