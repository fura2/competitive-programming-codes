#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

char ask(int x){
	printf("%d\n",x);
	fflush(stdout);

	char s[8]; scanf("%s",s);
	if(s[0]=='V') exit(0);
	return s[0];
}

int main(){
	int n; scanf("%d",&n);

	char r1=ask(0);

	int lo=0,hi=n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		char r2=ask(mi);
		if(((mi-lo)%2==0 && r1!=r2) || ((mi-lo)%2==1 && r1==r2)){
			hi=mi;
		}
		else{
			lo=mi;
			r1=r2;
		}
	}
	assert(false);

	return 0;
}
