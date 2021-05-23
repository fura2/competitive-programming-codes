#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,a,b; scanf("%d%d%d%d",&n,&m,&a,&b);

	vector<int> x(n,b);
	rep(i,m){
		int l,r; scanf("%d%d",&l,&r); l--;
		for(int j=l;j<r;j++) x[j]=a;
	}
	printf("%d\n",accumulate(x.begin(),x.end(),0));

	return 0;
}
