#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> l(n),r(n);
	rep(i,n) scanf("%d%d",&l[i],&r[i]), r[i]++;

	double ans=0;
	rep(i,n) for(int j=i+1;j<n;j++) {
		int tmp=0;
		for(int x=l[i];x<r[i];x++){
			tmp+=max(min(x,r[j])-l[j],0);
		}
		ans+=1.0*tmp/((r[i]-l[i])*(r[j]-l[j]));
	}
	printf("%.9f\n",ans);

	return 0;
}
