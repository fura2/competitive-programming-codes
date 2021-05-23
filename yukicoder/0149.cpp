#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int aw,ab,bw,bb,c,d;
	scanf("%d%d%d%d%d%d",&aw,&ab,&bw,&bb,&c,&d);

	if(c<=ab){
		bb+=c;
		ab-=c;
	}
	else if(ab<c){
		bb+=ab;
		bw+=c-ab;
		aw-=c-ab;
		ab=0;
	}
	printf("%d\n",aw+min(bw,d));

	return 0;
}
