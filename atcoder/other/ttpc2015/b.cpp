#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,b,c; scanf("%d%d%d",&n,&b,&c);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	for(int i=n-1;i>=0;i--){
		int x=min(b,c);
		ans+=a[i]*x;
		c-=x;
	}
	printf("%d\n",ans);

	return 0;
}
