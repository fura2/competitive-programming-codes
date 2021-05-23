#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int lo=1,hi=1e9+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		printf("? %d\n",mi);
		fflush(stdout);
		int x; scanf("%d",&x);
		if(x==1) lo=mi;
		else     hi=mi;
	}
	printf("! %d\n",lo);
	return 0;
}
