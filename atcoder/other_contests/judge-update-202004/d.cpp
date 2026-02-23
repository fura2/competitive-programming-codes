#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	rep(i,n-1) a[i+1]=gcd(a[i],a[i+1]);

	rep(_,q){
		int tar; scanf("%d",&tar);

		if(gcd(tar,a[n-1])!=1){
			printf("%d\n",gcd(tar,a[n-1]));
			continue;
		}

		int lo=-1,hi=n-1;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(gcd(tar,a[mi])==1) hi=mi;
			else                  lo=mi;
		}
		printf("%d\n",hi+1);
	}
	return 0;
}
