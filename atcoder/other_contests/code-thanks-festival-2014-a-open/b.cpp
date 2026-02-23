#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[3]; scanf("%d",&n);
	rep(i,3) scanf("%d",&a[i]);

	int ans=n;
	rep(i,3){
		int cnt=0;
		rep(j,n){
			cnt+=a[j%3];
			if(cnt>=n){
				ans=min(ans,j+1);
				break;
			}
		}
		rotate(a,a+1,a+3);
	}
	printf("%d\n",ans);

	return 0;
}
