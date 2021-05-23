#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,l,r; scanf("%d%d%d",&x,&l,&r);
	if     (x<l) printf("%d\n",l);
	else if(r<x) printf("%d\n",r);
	else         printf("%d\n",x);
	return 0;
}
