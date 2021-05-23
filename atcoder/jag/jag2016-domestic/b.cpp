#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,T; scanf("%d%d%d",&n,&m,&T);
	vector<bool> ok(T,true);
	rep(i,n){
		int a; scanf("%d",&a);
		for(int t=a-m;t<min(a+m,T);t++) ok[t]=false;
	}
	printf("%ld\n",count(ok.begin(),ok.end(),true));
	return 0;
}
