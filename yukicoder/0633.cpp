#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n-1);
	rep(i,n-1) scanf("%d",&a[i]);

	int ans=0,num=0;
	rep(i,n-1){
		int b,c; scanf("%d%d",&b,&c);
		num+=c-b;
		ans+=a[i]*num;
	}
	printf("%d\n",ans);

	return 0;
}
