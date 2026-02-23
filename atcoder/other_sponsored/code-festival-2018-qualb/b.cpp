#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	int a[100],b[100];
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	int ans=x**max_element(b,b+n);
	rep(i,n) ans+=a[i]*b[i];
	printf("%d\n",ans);

	return 0;
}
