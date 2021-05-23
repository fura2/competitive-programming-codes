#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y; scanf("%d%d",&x,&y);
	if(y==0){
		puts("ERROR");
	}
	else{
		printf("%.2f\n",100*x/y/100.0);
	}
	return 0;
}
