#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	int cnt=0;
	rep(i,n) cnt+=abs(a[i]-b[i]);
	puts(cnt<=k&&(k-cnt)%2==0?"Yes":"No");

	return 0;
}
