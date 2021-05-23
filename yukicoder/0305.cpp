#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int ask(int* a){
	rep(i,10) printf("%d",a[i]);
	puts("");
	fflush(stdout);
	int x; scanf("%d%*s",&x);
	return x;
}

int main(){
	int a[10];
	do{
		rep(i,10) a[i]=rng()%10;
	}while(ask(a)!=0);

	rep(i,10){
		rep(d,10){
			a[i]=d;
			if(ask(a)==i+1) break;
		}
	}

	return 0;
}
