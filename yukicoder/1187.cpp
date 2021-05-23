#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	char s[8]; scanf("%s",s);
	return s[0]=='s';
}

int main(){
	int lo=0,hi=500;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(ask(2*mi) || ask(2*mi+1)) lo=mi; else hi=mi;
	}

	printf("! %d\n",ask(2*lo+1)?2*lo+1:2*lo);
	fflush(stdout);

	return 0;
}
