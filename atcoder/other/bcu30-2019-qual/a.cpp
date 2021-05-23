#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,p; scanf("%d%d",&n,&p);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	rep(i,n){
		if(p<a[i]) break;
		p-=a[i];
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
