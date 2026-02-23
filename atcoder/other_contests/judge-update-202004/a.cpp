#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int s,l,r; scanf("%d%d%d",&s,&l,&r);
	printf("%d\n",max(min(s,r),l));
	return 0;
}
