#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int w,d; scanf("%d%d",&w,&d);
	rep(i,d-1) w-=w/((lint)(d-i)*(d-i));
	printf("%d\n",w);
	return 0;
}
