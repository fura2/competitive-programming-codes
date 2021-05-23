#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int j,m,b; scanf("%d,%d,%d",&j,&m,&b);
	printf("合計点:%d\n平均点:%.1f\n",j+m+b,(j+m+b)*10/3/10.0);
	return 0;
}
