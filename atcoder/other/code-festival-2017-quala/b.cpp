#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	rep(i,h+1) rep(j,w+1) if(i*(w-j)+j*(h-i)==k) return puts("Yes"),0;
	puts("No");
	return 0;
}
