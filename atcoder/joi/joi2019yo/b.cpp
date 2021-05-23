#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int m; scanf("%d",&m);
	rep(_,m){
		int k; scanf("%d",&k); k--;
		if(a[k]<2019 && (k==n-1 || a[k+1]!=a[k]+1)) a[k]++;
	}
	rep(i,n) printf("%d\n",a[i]);

	return 0;
}
