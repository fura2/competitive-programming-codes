#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int ask(int a,int b,int c,int d,int t){
	int x[4]={a,b,c,d};
	rotate(x,x+(4-t)%4,x+4);
	printf("%d %d %d %d\n",x[0],x[1],x[2],x[3]);
	fflush(stdout);
	int res; scanf("%d%*d",&res);
	return res;
}

int main(){
	int ans[4];
	rep(t,4){
		int res[10];
		rep(a,10){
			if(a<=6) res[a]=ask(a,7,8,9,t);
			else     res[a]=ask(a,0,1,2,t);
		}
		if(*max_element(res,res+7)==*min_element(res,res+7)){
			ans[t]=max_element(res+7,res+10)-res;
		}
		else{
			ans[t]=max_element(res,res+7)-res;
		}
	}
	ask(ans[0],ans[1],ans[2],ans[3],0);

	return 0;
}
