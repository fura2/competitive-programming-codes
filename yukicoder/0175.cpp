#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,n; scanf("%d%d",&l,&n);
	printf("%d\n",(1<<(l-3))*n);
	return 0;
}
