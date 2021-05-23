#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d",&x[i]);
	rep(i,n) scanf("%d",&y[i]);

	int mn=INF;
	rep(i,n) mn=min(mn,x[i]+y[i]);

	printf("%d\n0\n",mn);
	rep(i,n) printf("%d\n",min(x[i],mn));
	printf("%d\n",mn);

	return 0;
}
