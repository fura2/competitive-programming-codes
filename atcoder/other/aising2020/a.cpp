#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,r,d; scanf("%d%d%d",&l,&r,&d);
	printf("%d\n",r/d-(l-1)/d);
	return 0;
}
