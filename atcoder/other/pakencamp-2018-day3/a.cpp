#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int y,m,d; scanf("%d%d%d",&y,&m,&d);
	if(m==12 && d==25){
		printf("%d\n",y-2018);
	}
	else{
		puts("NOT CHRISTMAS DAY");
	}
	return 0;
}
