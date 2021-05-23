#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n+1);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	lint ans=0,b_max=0,t=0,c=0;
	// t = (町 i に辿りつくために必要な最小日数), c = (t 日かけて町 i に着いたときの所持金の最大値)
	rep(i,n+1){
		b_max=max(b_max,b[i]);
		ans=max(ans,c+(n-t)*b_max);
		if(i==n) break;

		if(c+a[i]>=0){
			t++;
			c+=a[i];
		}
		else if(b_max==0){ // 町 i+1 に到達できない
			break;
		}
		else{ // これまでに訪れた b が最大の町で k 日滞在してから, 町 i+1 に進む
			lint k=(-(c+a[i])+b_max-1)/b_max;
			t+=k+1;
			c+=k*b_max+a[i];
		}
		if(t>n) break;
	}
	printf("%lld\n",ans);

	return 0;
}
