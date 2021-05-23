#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[]={2,3,5,7,11,13},b[]={4,6,8,9,10,12};

	int k; scanf("%d",&k);
	int cnt=0;
	rep(i,6) rep(j,6) if(a[i]*b[j]==k) cnt++;
	printf("%.15f\n",cnt/36.0);

	return 0;
}
