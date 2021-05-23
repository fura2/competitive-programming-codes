#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k,n,m; scanf("%d%d%d",&k,&n,&m);
	int sum=0;
	rep(i,m){ int a; scanf("%d",&a); sum+=a; }
	printf("%d\n",k*n>=sum?k*n-sum:-1);
	return 0;
}
