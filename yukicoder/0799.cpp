#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",(b-a+1)*(d-c+1)-max(min(b,d)-max(a,c)+1,0));
	return 0;
}
