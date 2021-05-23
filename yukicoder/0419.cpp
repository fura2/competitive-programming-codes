#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int b,c; scanf("%d%d",&b,&c);
	if(b==c){
		printf("%.9f\n",sqrt(2)*b);
	}
	else{
		if(b>c) swap(b,c);
		printf("%.9f\n",sqrt(c*c-b*b));
	}
	return 0;
}
