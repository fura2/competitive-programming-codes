#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,x; scanf("%d%d%d%d",&a,&b,&c,&x);
	puts(a+b+c<=x&&x<=a+b+c+3?"Yes":"No");
	return 0;
}
