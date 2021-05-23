#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	puts(3*((a+c-1)/c)<=2*((a+b-1)/b)?"YES":"NO");
	return 0;
}
