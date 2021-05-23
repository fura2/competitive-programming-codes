#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T; scanf("%d%d",&n,&T);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int t=0;
	rep(i,n){
		t=max(t,a[i]);
		t=a[i]+(t-a[i]+T-1)/T*T;
	}
	printf("%d\n",t);

	return 0;
}
