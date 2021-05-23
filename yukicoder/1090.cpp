#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	vector<int> a(n-1);
	rep(i,n-1) scanf("%d",&a[i]);

	vector<int> x(n);
	rep(i,n-1) x[i+1]=x[i]+a[i];

	rep(i,n){
		if(i>0) x[i]=max(x[i],x[i-1]+d);
		printf("%d%c",x[i],i<n-1?' ':'\n');
	}

	return 0;
}
