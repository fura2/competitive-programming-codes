#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int L; scanf("%d",&L);

	int ans=0;
	for(int m=2;4*m*m<=L;m++){
		for(int n=1;n<m;n++){
			int a=m*m-n*n;
			int b=2*m*n;
			int c=m*m+n*n;
			if(4*(a+b+c)>L) break;
			if(gcd(m,n)==1 && (m-n)%2==1){
				ans++;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
