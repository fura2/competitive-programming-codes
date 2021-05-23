#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int x=0;
	rep(i,m){
		int d; scanf("%d",&d);
		x+=d;
		if(x<n) x+=a[x];
		if(x>=n-1){
			printf("%d\n",i+1);
			break;
		}
	}

	return 0;
}
