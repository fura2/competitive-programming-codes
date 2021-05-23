#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d1,d2,d3,s; scanf("%d%d%d%d",&d1,&d2,&d3,&s);
	puts(s==1||d1+d2+d3<2?"SURVIVED":"DEAD");
	return 0;
}
