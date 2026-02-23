#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,k; scanf("%d%d",&x,&k);

	int ten=1;
	rep(i,k) ten*=10;

	printf("%d\n",(x/ten+1)*ten);

	return 0;
}
