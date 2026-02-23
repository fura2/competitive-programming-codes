#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	double ans=0;
	rep(i,k) ans+=1+1.0*a[i]/a[i+n-k];
	printf("%.9f\n",ans);

	return 0;
}
