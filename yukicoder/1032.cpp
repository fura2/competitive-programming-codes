#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int hist[200001]={};
	rep(i,n){
		int a; scanf("%d",&a);
		hist[a]++;
	}
	rep(i,m) printf("%d %d\n",i+1,hist[i+1]);
	return 0;
}
