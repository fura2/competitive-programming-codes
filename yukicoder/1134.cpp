#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	int k; scanf("%d",&k); k--;

	if(count(a.begin(),a.end(),a[0])==n) return puts("50"),0;

	double mean=accumulate(a.begin(),a.end(),0.0)/n;
	double var=0;
	rep(i,n) var+=(a[i]-mean)*(a[i]-mean);
	var/=n;
	double sd=sqrt(var);
	printf("%d\n",int(10*(a[k]-mean)/sd+50));

	return 0;
}
