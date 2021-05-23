#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int a[4],b[4];
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	sort(a,a+n);
	sort(b,b+n);

	int cnt1=0,cnt2=0;
	do{
		do{
			int tmp=0;
			rep(i,n){
				if(a[i]>b[i]) tmp++;
				else          tmp--;
			}
			if(tmp>0) cnt1++;
			cnt2++;
		}while(next_permutation(b,b+n));
	}while(next_permutation(a,a+n));

	printf("%.9f\n",1.0*cnt1/cnt2);

	return 0;
}
