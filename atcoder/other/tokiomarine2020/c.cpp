#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> sum(n+1);
	do{
		rep(i,n+1) sum[i]=0;
		rep(i,n){
			sum[max(i-a[i],0)]++;
			sum[min(i+a[i]+1,n)]--;
		}
		rep(i,n) sum[i+1]+=sum[i];
		rep(i,n) a[i]=sum[i];

		k--;
	}while(k>0 && count(a.begin(),a.end(),n)<n);

	rep(i,n) printf("%d%c",a[i],i<n-1?' ':'\n');

	return 0;
}
