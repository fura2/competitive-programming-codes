#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	printf("%d\n",min((n+h-1)/h,(n+w-1)/w));
	return 0;
}
