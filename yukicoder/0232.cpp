#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int t,a,b; scanf("%d%d%d",&t,&a,&b);

	if(max(a,b)>t) return puts("NO"),0;
	if(a==0 && b==0 && t==1) return puts("NO"),0;

	puts("YES");

	int y=0,x=0;
	if(max(a,b)%2!=t%2){
		if(y==a && x==b){
			puts("v<");
			puts("^");
			puts(">");
			t-=2;
		}
		else if(y<a && x<b) puts("^"), y++;
		else if(y==a) puts("v"), y--;
		else if(x==b) puts("<"), x--;
		t--;
	}
	while(y<a || x<b){
		if(y<a) putchar('^'), y++;
		if(x<b) putchar('>'), x++;
		puts("");
		t--;
	}
	while(t>0){
		puts("v");
		puts("^");
		t-=2;
	}

	return 0;
}
