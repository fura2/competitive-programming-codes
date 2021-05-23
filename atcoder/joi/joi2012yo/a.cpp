#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d,e; scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	printf("%d\n",min({a,b,c})+min(d,e)-50);
	return 0;
}
