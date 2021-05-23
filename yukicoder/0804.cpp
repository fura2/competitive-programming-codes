#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
	int i;
	for(i=1;i<=a;i++){
		if(b<c*i || d<c*i+i) break;
	}
	printf("%d\n",i-1);
	return 0;
}
