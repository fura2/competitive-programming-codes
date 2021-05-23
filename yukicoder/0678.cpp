#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,xl,xr; scanf("%d%d%d",&n,&xl,&xr);
	vector<int> t(n),b(n),l(n),r(n);
	rep(i,n) scanf("%d%d%d%d",&l[i],&t[i],&r[i],&b[i]);

	vector<bool> flag(n,true);
	for(int x=xl;x<=xr;x++){
		int i0=-1;
		rep(i,n) if(l[i]<=x && x<=r[i]) {
			if(i0==-1 || b[i]>b[i0]) i0=i;
		}
		if(i0!=-1) flag[i0]=false;
	}

	rep(i,n) printf("%d\n",!flag[i]);

	return 0;
}
