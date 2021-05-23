#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int res; scanf("%d",&res);
	return res;
}

void answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
}

int main(){
	int res=ask(100);
	if(res==0){
		answer(100);
	}
	else if(res==-1){
		int t;
		for(t=1;ask(0)!=0;t++);
		answer(t);
	}
	else{
		int t=1;
		int lo=100,hi=1e9+1;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(ask(mi-t)!=-1) lo=mi;
			else              hi=mi;
			t++;
		}
		answer(lo);
	}

	return 0;
}
