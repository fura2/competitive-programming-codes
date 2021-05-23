#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	for(int x=1;x<128;x++){
		if(x%3==a && x%5==b && x%7==c){
			printf("%d\n",x);
		}
	}
	return 0;
}
