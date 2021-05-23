#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,x; scanf("%d%d%d",&a,&b,&x);
	if(abs(a-x)<=abs(b-x) || x==1){
		printf("%d\n",abs(a-x)+x);
	}
	else if(a!=0){
		printf("%d\n",abs(b-x)+min(abs(x-a)+a,abs(x-1)+a));
	}
	else{
		printf("%d\n",abs(b-x)+abs(x-1)+2);
	}
	return 0;
}
