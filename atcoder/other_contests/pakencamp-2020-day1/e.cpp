#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);
	if(x==y){
		if(x==0){
			puts("1 1");
		}
		else{
			puts("-1");
		}
	}
	else if(x<y){
		if(x==0){
			printf("%d %d\n",2*y,y);
		}
		else{
			printf("%d %d\n",x+y,y);
		}
	}
	else{ // x>y
		if(y==0){
			printf("%d %d\n",x,2*x);
		}
		else{
			printf("%d %d\n",x,x+y);
		}
	}
	return 0;
}
