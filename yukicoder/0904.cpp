#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n-1),b(n-1);
	int asum=0,bsum=0;
	rep(i,n-1){
		scanf("%d%d",&a[i],&b[i]);
		asum+=a[i];
		bsum+=b[i];
	}

	int x_min=0,x_max=bsum,y_min=0,y_max=asum;
	rep(i,n-1){
		x_min=max(x_min,b[i]-(asum-a[i]));
		y_min=max(y_min,a[i]-(bsum-b[i]));
	}
	printf("%d\n",min(x_max-x_min+1,y_max-y_min+1));

	return 0;
}
