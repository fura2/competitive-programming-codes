#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool vis[1600];
int memo[1600];

int ask(int i){
	if(vis[i]) return memo[i];
	vis[i]=true;

	printf("? %d\n",i);
	fflush(stdout);
	int a; scanf("%d",&a);
	return memo[i]=a;
}

void answer(int a){
	printf("! %d\n",a);
	fflush(stdout);
}

void solve(){
	int fib[18]={0,1};
	rep(i,16) fib[i+2]=fib[i]+fib[i+1];

	int n; scanf("%d",&n);

	rep(i,1600){
		if(1<=i && i<=n){
			vis[i]=false;
		}
		else{
			vis[i]=true;
			memo[i]=-i-1;
		}
	}

	int lo=0,mi1=fib[15],mi2=fib[16],hi=fib[17];
	int a_mi1=ask(mi1),a_mi2=ask(mi2);
	for(int i=17;i>=4;i--){
		if(a_mi1<a_mi2){
			tie(lo,mi1,hi)=make_tuple(mi1,mi2,hi);
			mi2=lo+fib[i-2];
			a_mi1=a_mi2;
			a_mi2=ask(mi2);
		}
		else{
			tie(lo,mi2,hi)=make_tuple(lo,mi1,mi2);
			mi1=lo+fib[i-3];
			a_mi2=a_mi1;
			a_mi1=ask(mi1);
		}
	}
	answer(max(a_mi1,a_mi2));
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
