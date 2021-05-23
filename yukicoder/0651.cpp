#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a; scanf("%d",&a);
	int t=60*a/100;
	printf("%2d:%02d\n",10+t/60,t%60);
	return 0;
}
