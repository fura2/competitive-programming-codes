#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d1,d2; scanf("%d%d",&d1,&d2);
	if     (d2< d1)   puts("0");
	else if(d2==d1)   puts("4");
	else if(d2< 2*d1) puts("8");
	else if(d2==2*d1) puts("4");
	else              puts("0");
	return 0;
}
