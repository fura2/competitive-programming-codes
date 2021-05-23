#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int f(int n,int m,int x){
	if(x%(2*m)<m) return x%(2*m);
	else          return (2*m-1-x%(2*m))%m;
}

int main(){
	int n,m,x,y; scanf("%d%d%d%d",&n,&m,&x,&y); x--; y--;
	puts(f(n,m,x)==f(n,m,y)?"YES":"NO");
	return 0;
}
