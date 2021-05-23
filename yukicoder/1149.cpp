#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

pair<int,int> ask(int k,int x){
	printf("%d %d\n",k,x);
	fflush(stdout);
	int t; scanf("%d",&t);
	if(t==0) exit(0);
	scanf("%d%d",&k,&x);
	return {k,x};

}

int main(){
	int n; scanf("%d",&n);

	int k,x;
	tie(k,x)=ask(n%2==0?2:1,(n+1)/2);
	while(1){
		if(x<(n+1)/2){
			tie(k,x)=ask(k,x+(n+2)/2);
		}
		else{
			tie(k,x)=ask(k,x-(n+2)/2);
		}
	}

	return 0;
}
