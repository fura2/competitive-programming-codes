#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int ask(char op,int l,int r){
	if(op=='M'){
		printf("%c %d %d\n",op,l+1,r);
	}
	else if(op=='S'){
		printf("%c %d %d\n",op,l+1,r+1);
	}
	else{
		printf("%c\n",op);
	}
	fflush(stdout);
	int res; scanf("%d",&res);
	return res-1;
}

void solve(){
	int n=100;
	rep(i,n-1){
		int idx=ask('M',i,n);
		if(idx!=i) ask('S',i,idx);
	}
	ask('D',-1,-1);
}

int main(){
	int t; scanf("%d%*d",&t);
	rep(_,t){
		solve();
	}
	return 0;
}
