#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n; scanf("%d",&n);

	printf("%d\n",(1<<n)-1);
	for(int i=1;i<(1<<n);i++){
		rep(j,1<<n) putchar(popcount(i&j)%2==0?'A':'B');
		puts("");
	}

	return 0;
}
