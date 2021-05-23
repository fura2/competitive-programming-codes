#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,m; scanf("%d:%d",&h,&m);
	m+=5;
	if(m>=60) m-=60, h++;
	if(h>=24) h-=24;
	printf("%02d:%02d\n",h,m);
	return 0;
}
