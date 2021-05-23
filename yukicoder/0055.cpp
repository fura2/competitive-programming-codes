#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x1,y1,x2,y2,x3,y3;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);

	int a2=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
	int b2=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
	int c2=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

	int x4,y4;
	if(a2==b2 && a2+b2==c2){
		x4=x1+x2-x3;
		y4=y1+y2-y3;
	}
	else if(b2==c2 && b2+c2==a2){
		x4=x2+x3-x1;
		y4=y2+y3-y1;
	}
	else if(c2==a2 && c2+a2==b2){
		x4=x3+x1-x2;
		y4=y3+y1-y2;
	}
	else return puts("-1"),0;
	printf("%d %d\n",x4,y4);

	return 0;
}
