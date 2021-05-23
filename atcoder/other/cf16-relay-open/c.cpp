#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(1<<n);
	rep(i,1<<n) scanf("%d",&a[i]);

	rep(i,n){
		rep(j,1<<(n-i-1)){
			int x=a[(1<<i+1)*j],y=a[(1<<i+1)*j+(1<<i)];
			if(x!=y) a[(1<<i+1)*j]=abs(x-y);
		}
	}
	printf("%d\n",a[0]);

	return 0;
}
